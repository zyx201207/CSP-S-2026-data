#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
#define N 2000005
using namespace std;
int id,T,n,d,a[N];
int f[5005][5005],g[5005][5005],t[5005];
int q[5005],head,tail;
void solvenn(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=n+1,g[i][j]=0;
	for(int i=1;i<=n;i++)
		f[i][i]=0,g[i][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++)
			t[j]=0;
		head=1,tail=0;
		q[++tail]=i,t[0]++;
		for(int j=i+1;j<=n;j++){
			while(a[q[head]]+d<a[j]&&head<=tail)
				t[f[i][q[head]]]-=g[i][q[head]],head++;
			f[i][j]=f[i][q[head]]+1;
			while(f[i][q[tail]]>f[i][j]&&head<=tail)
				t[f[i][q[tail]]]-=g[i][q[tail]],tail--;
			q[++tail]=j;
			g[i][j]=t[f[i][j]-1];
			t[f[i][j]]+=g[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans+=(g[i][j]==2);
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>id>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(n<=5000){
			solvenn();
			continue;
		}
	}
	return 0;
}
