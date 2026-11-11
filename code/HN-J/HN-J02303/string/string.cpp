#include<bits/stdc++.h>
using namespace std;
struct A{
	int num;
	char value;
}a[200010];
int n,ans,cnt,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i = 1;i <= n;i ++){
		cin>>a[i].num>>a[i].value;
		cnt += a[i].num; 
	}
	if(cnt % 2)cnt = cnt / 2 + 1;
	else cnt /= 2;
	while(1){
		sum ++;
		if(cnt > a[sum].num)cnt -= a[sum].num;
		else{
			if(cnt = a[sum].num){
				for(int i = n + 1;i >= sum + 1;i --){
					a[i].num = a[i - 1].num;
					a[i].value = a[i - 1].value;
				}
				a[sum].num = a[sum + 1].num - 1;
				a[sum + 1].num = 1;
				int l  =1;
				int r = n + 1;
				while(l != sum && r != sum){
					if(a[l].num > a[r].num){
						if(a[l].value == a[r].value){
							a[l].num -= a[r].num;
							r --; 
						}
						else{
							ans += a[r].num;
							a[l].num -= a[r].num;
							r --;
						}
					}
					else if(a[l].num == a[r].num){
						if(a[l].value == a[r].value){
							r --; 
							l ++;
						}
						else{
							ans += a[r].num;
							r --;
							l ++;
						}
					}
					else if(a[l].num < a[r].num){
						if(a[l].value == a[r].value){
							a[r].num -= a[l].num;
							l ++;
						}
						else{
							ans += a[l].num;
							a[r].num -= a[l].num;
							l ++;
						}
					}
				}
				break;
			}
			else{
				for(int i = n + 2;i >= sum + 2;i --){
					a[i].num = a[i - 2].num;
					a[i].value = a[i - 2].value;
				}
				a[sum].num = cnt - 1;
				a[sum + 1].num = 1 ;
				a[sum + 2].num -= cnt; 
				int l = 1,r = n +2;
				
			}
		}
	}
	cout<<ans;
}
