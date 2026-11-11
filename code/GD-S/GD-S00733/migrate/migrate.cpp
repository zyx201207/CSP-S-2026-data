#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10,NN=5e3+10;
int c,T,n,vis[NN][NN],f[NN][NN];
ll a[N],d;
ll ans;
ll solve1(){
	ans=0;
	memset(f,0,sizeof f);
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++)
	for(int j=1;j<i;j++){
		f[j][i]=INT_MAX/2;
		for(int k=i-1;k>=j;k--)
			if(a[i]-a[k]<=d){
				if(f[j][i]>=f[j][k]+1){
					if(f[j][i]==f[j][k]+1)vis[j][i]++;
					else vis[j][i]=1;
					f[j][i]=f[j][k]+1;
//					cout<<j<<' '<<k<<' '<<i<<' '<<vis[j][i]<<'\n';
				}
			}else break;
//		cout<<j<<' '<<i<<' '<<vis[j][i]<<'\n';
//		cout<<j<<' '<<i<<' '<<vis[j][i]<<'\n';
		if(vis[j][i]==2)ans++;
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		memset(a,0,sizeof a);
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
//			cout<<a[i]<<' ';
		}
		if(c<=10){
			cout<<solve1()<<'\n';
		}
//		cout<<'\n';
	} 
	return 0;
}

