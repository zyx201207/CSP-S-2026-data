#include<bits/stdc++.h>
using namespace std;
#ifdef _WIN32
#define gc _getchar_nolock
#else
#define gc getchar_unlocked
#endif
const int N=2e4+100; 
int c,n,m,d,q;
int w[N],k[N];
int fa[505][N];
vector<int> e[N+505];
int read()
{
	int c,k=0,f=1;
	c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(;isdigit(c);c=gc())k=k*10+c-'0';
	return k*f;
}
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);cout.tie(nullptr);
c=read();n=read();m=read();d=read();q=read();
for(int i=1;i<=n;++i)
for(int j=1;j<=m;++j)
fa[i][j]=j;

for(int i=1;i<=m;++i)
{
	w[i]=read();
}
for(int i=1;i<=n;++i)
{
	cin>>k[i];
	for(int j=1;j<=k[i];++j)
	{
		int a,t;
		a=read();t=read();
		
	
	}
 }

 for(int i=1;i<=q;++i)
 {
 	int s,t;
 	s=read();t=read();
 	cout<<w[s]+w[t]<<"\n";
 }
return 0;
}
