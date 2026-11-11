#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
	long long id[N]; 
     long long f[N];
int main(){
	freopen("migrate2.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long c,t,n,d;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
	for(int j=1;j<=n;j++){
		cin>>id[j];
	}
	f[1]=1;
	for(int j=2;j<=n;j++){
		f[j]=f[j-1];
		for(int k=j;k>=1;k--){
			if(j-k>0)
		f[j]=max(f[j],f[k]+1);
		}
		
	}
	long long ans=0;
	for(int j=1;j<=n;j++){
		cout<<f[j]<<" ";
		if(f[j]==2) ans++;
	} 
	cout<<ans<<'\n';
	}

	return 0;
}
