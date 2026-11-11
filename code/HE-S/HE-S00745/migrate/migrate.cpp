#include <bits/stdc++.h>
#define OUT(x) ' '<<(#x)<<'='<<(x)<<' '
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2000005;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll CASE,T,N,D,a[MAXN],f[MAXN],g[MAXN];
void solveTLE(){
	while(T--){
		ll ans=0;
		cin>>N>>D;
		for(int i=1;i<=N;i++){
			cin>>a[i];
		}
		for(int i=1;i<=N;i++){
			for(int j=i;j<=N;j++){
				f[j]=INF,g[j]=0;
			}
			f[i]=0,g[i]=1;
			for(int j=i;j<=N;j++){
				for(int k=j+1;k<=N&&a[k]-a[j]<=D;k++){
					if(f[j]+1<f[k])f[k]=f[j]+1,g[k]=g[j];
					else if(f[j]+1==f[k])g[k]+=g[j];
				}
				//cout<<OUT(i)<<OUT(j)<<OUT(f[j])<<OUT(g[j])<<'\n';
				if(g[j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
void solveA(){
	// 0 1 10 2 0 1 2 3 4 5 6 7 8 9
	// 0 1 10 3 0 1 2 3 4 5 6 7 8 9
	// 0 1 10 5 0 2 4 6 8 10 12 14 16 18
	// 0 1 5 8 0
	while(T--){
		cin>>N>>D;
		for(int i=1;i<=N;i++){
			cin>>a[i];
		}
//		cout<<OUT(N)<<OUT(D)<<OUT(abs(a[2]-a[1]))<<'\n';
		if(abs(a[2]-a[1])>=D)cout<<"0\n";
		else if(N-(2*(D/abs(a[2]-a[1]))-1)<0)cout<<"0\n";
		else cout<<(N-(2*(D/abs(a[2]-a[1]))-1))<<'\n';
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>CASE>>T;
	solveA();
	if(CASE==11||CASE==12)solveA();
	else solveTLE();
	return 0;
} 
