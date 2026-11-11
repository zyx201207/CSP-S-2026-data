#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,m,a[2000010];
int cnt;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cnt=a[2]-a[1];
		if(m>=cnt*(n-1)){
			if(n==4){
				cout<<1<<'\n';
			}else{
				cout<<0<<'\n';
			}
		}else if(m>=3*cnt){
			if(a[n]<=5*cnt){
				cout<<1<<'\n';
			}else{
				cout<<0<<'\n';
			}
		}else if(m>=cnt&&m<2*cnt){
			cout<<n*(n-1)/2<<'\n';
		}else{
			cout<<n-3<<'\n';
		}
	}
	return 0;
}
//数据水一点，求你了qwq 
