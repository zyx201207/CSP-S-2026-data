#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n,d,xb=-1;
		cin>>n>>d;
		long long s[100005],ds[100005];
		for(int j=1;j<=n;j++){
			cin>>s[j];
		} 
		for(int j=1;j<=n;j++){
			if(s[j]-s[1]<=d && s[n]-s[j]<=d){
				xb=j;
			}
		}
		if(xb>=1){
			cout<<(xb-1)*(n-xb);
		}else if(d>=n){
			cout<<0<<'\n';
		}else{
			cout<<0<<'\n';
		}
	}
} 
