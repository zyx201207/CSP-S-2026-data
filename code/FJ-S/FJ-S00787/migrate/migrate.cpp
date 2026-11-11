#include<bits/stdc++.h>
using namespace std;
long long a[2001000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==13||c==14){
			continue;
		}
		int ans=0;
		if(d>(a[n]-a[1])){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						long long x=a[j]-a[i];
						long long y=a[k]-a[j];
						long long z=a[l]-a[k];
						if(x+y<=d&&y+z<=d&&x+y+z>d){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	if(c==13||c==14){
		cout<<0;
	}
	return 0;
}
