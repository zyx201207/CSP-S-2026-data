#include<bits/stdc++.h>
#define fs first
#define sc second
#define ll long long
using namespace std;
const int N=5e3+5;
ll T,n,d,cnt,a[N];
pair<ll,ll> f[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>T>>T;
	while(T--){
		cin>>n>>d,cnt=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]={1e18,0};
		for(int i=1;i<=n;i++) cin>>a[i],f[i][i]={0,1};
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
			for(int k=j;k>=i&&a[j]-a[k]<=d;k--)
				if(f[i][k].fs+1<f[i][j].fs) f[i][j]={f[i][k].fs+1,f[i][k].sc};
				else f[i][j].sc+=f[i][k].sc;
			if(f[i][j].sc==2) cnt++;
		}
		cout<<cnt<<'\n';
	}
	return 0; 
}
