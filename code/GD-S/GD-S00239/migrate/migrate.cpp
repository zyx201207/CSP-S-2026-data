#include<bits/stdc++.h>
using namespace std;
int c,t,n,f[5005][5005],p,ans,js[5005];
long long d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		ans=0;
		for(int i=1;i<=n;i++){
			p=i,f[i][i]=0,js[i]=1;
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[j-1]>d)	break;
				if(x[j]-x[p]>d)	p=j-1;
				f[i][j]=f[i][p]+1,js[j]=js[p];
				if(p-1>=i && x[j]-x[p-1]<=d)	js[j]+=js[p-1];
				if(p-2>=i && x[j]-x[p-2]<=d)	js[j]+=js[p-2];		
				if(js[j]>2)	js[j]=3;
				else if(js[j]==2)	ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
