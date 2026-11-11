#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5003;
int c,T,n,s,f[N][N],g[N][N];
ll d,a[2000003];
bool v[N][N],fl;
void dfs(int l,int r){
	if(v[l][r])return;
	v[l][r]=1;
	int&mn=f[l][r];
	int&k=g[l][r];
	if(a[r]-a[l]<=d){
		mn=k=1;
		return;
	}
	int L=l,R=r;
	while(L<R){
		int md=(L+R+1)/2;
		if(a[md]-a[l]<=d)L=md;
		else R=md-1;
	}
	mn=1e9,k=0;
	if(L!=l){
		dfs(L,r);
		mn=f[L][r]+1,k=g[L][r];
	}
	if(mn>=1e9)return;
	for(int i=L-1;i>l&&k<3;i--){
		dfs(i,r);
		if(f[i][r]+1==mn)k+=g[i][r];
		else break;
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n==1){
			cout<<"0\n";
			continue;
		}
		if(c<11){
			for(int i=1;i<=n;i++){
				v[i][i]=1,f[i][i]=0,g[i][i]=1;
				for(int j=i+1;j<=n;j++)v[i][j]=0;
			}
			s=0;
			for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++){
				dfs(i,j);
				s+=g[i][j]==2;
			}
			cout<<s<<'\n';
		}else if(c<13){
			d/=a[2]-a[1];
			if(d<2)cout<<"0\n";
			else cout<<max(0ll,n-d*2+1)<<'\n';
		}else{
			s=0;
			for(int i=1;i+3<=n;i++)s+=a[i+3]-a[i]>d&&a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d;
			cout<<s<<'\n';
		}
	}
}
