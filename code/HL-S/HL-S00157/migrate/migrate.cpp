#include<bits/stdc++.h>
using namespace std;
long long sz[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c,t;
	for(int i=1;i<=t;i++){
		long long n,d,l,ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>sz[j];
		}
		l=sz[2]-sz[1];
		d/=l;
		for(int j=0;j<=n;j++){
			ans+=min(j,d-1);
		}
		cout<<ans<<endl;
	} 
	return 0;
}
