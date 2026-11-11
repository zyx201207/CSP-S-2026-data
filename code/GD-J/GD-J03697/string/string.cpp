#include<bits/stdc++.h>
using namespace std;
long long ans;
int n;
struct NODE{
	int num;
	char c;
}str[200010];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>str[i].num>>str[i].c;
	int l = 1,r = n;
	while(l < r){
		if(str[l].c == str[r].c){
			if(str[l].num == str[r].num){
				str[l].num = str[r].num = 0;
				l++;
				r--;
			}else if(str[l].num > str[r].num){
				str[l].num -= str[r].num;
				str[r].num = 0;
				r--;
			}else{
				str[r].num -= str[l].num;
				str[l].num = 0;
				l++;
			}
		}else{
			if(str[l].num == str[r].num){
				ans += str[l].num;
				str[l].num = str[r].num = 0;
				l++;
				r--;
			}else if(str[l].num > str[r].num){
				ans += str[r].num;
				str[l].num -= str[r].num;
				str[r].num = 0;
				r--;
			}else{
				ans += str[l].num;
				str[r].num -= str[l].num;
				str[l].num = 0;
				l++;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
