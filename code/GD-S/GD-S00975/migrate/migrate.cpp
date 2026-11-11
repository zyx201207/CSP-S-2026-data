#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,x,y,z) for(int i=x;i<=y;i+=z)
#define REP(i,x,y,z) for(int i=x;i>=y;i-=z)
void rd(int &x){
	int f=1;x=0;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0')x=x*10+(c-'0'),c=getchar();
	x*=f;
}const int N=2e6+10;
int n,d,a[N],ans;
void solve(){
	map<int,map<int,int>>f,de;
	rd(n),rd(d);FOR(i,1,n,1)rd(a[i]);
	FOR(i,1,n,1){
		int l=i;
		FOR(j,i+1,n,1){
			f[i][j]=1e12;
			while(l<=n&&(a[j]-a[l])>d)l++;
			FOR(k,l,j-1,1){
				int aaa=f[i][k]+1;
				if(aaa<f[i][j])f[i][j]=aaa,de[i][j]=1;
				else if(aaa==f[i][j])de[i][j]++;
			}if(de[i][j]==2)ans++;
		}
	}cout<<ans<<"\n";ans=0;
}signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int C,_;rd(C),rd(_);while(_--)solve();
	return 0;
}
