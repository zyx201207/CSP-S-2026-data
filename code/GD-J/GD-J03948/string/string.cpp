#include <bits/stdc++.h>
using namespace std;
struct ab{
	int num;
	char s;
}a[200010];
int n;
 long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].s;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].s!=a[r].s){
			cnt+=min(a[l].num,a[r].num);
			if(a[l].num>a[r].num){
				a[l].num=a[l].num-a[r].num;
				r--;
			}else if(a[l].num<a[r].num){
				a[r].num=a[r].num-a[l].num;
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l].num>a[r].num){
				a[l].num=a[l].num-a[r].num;
				r--;
			}else if(a[l].num<a[r].num){
				a[r].num=a[r].num-a[l].num;
				l++;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
