//GZ-S00257 贵阳市云岩区中天中学 侯恩彤 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n,m;
int a[N],ans;
bool flag = 1;
bool CR7 = 1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(i!=a[i]){
			flag = 0;
		}
	}
	for(int i = 3;i <= n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			CR7 = 0;
		}
	}
	if(CR7){
		int jj = a[2]-a[1];
		for(int i = 1;i <= n;i++){
			int ag = (a[i]-a[1])/jj+1;
			int sum = ag*(a[i]+a[1])/2;
			if(sum>m){
				break;
			}
			else{
				ans = i+1;
			}
		}
		if(ans>n){
			ans = n;
		}
		cout<<ans;
		return 0;
	}
	if(flag){
		for(int i = 1;i <= n;i++){
			int sum = i*(i+1)/2;
			if(sum>m){
				break;
			}
			else{
				ans = i+1;
			}
		}
		if(ans>n){
			ans = n;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++){
		int res = 0;
		for(int j = 1;j <= i;j++){
			res+=abs(a[j]-a[i]);
		}
		if(res>m){
			break;
		}
		else{
			ans = i;
		}
	}
	cout<<ans;
	return 0;
}
