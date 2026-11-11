#include<bits/stdc++.h>
using namespace std;
#define gc() getchar()
template<typename TP>
inline TP read(){
	TP f=1,x=0;char ch=gc();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=gc();}
	while(ch>='0' && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc();}
	return f*x;
}
const int N=1e5+5;
typedef long long ll;
int n,casenum,T,minst,mincnt,ans;
string mins;
ll d,x[N];
void dfs(int v,int p,int st){
	if(p==v){
		if(st==minst) mincnt++;
		else if(st<minst) minst=st,mincnt=1;
		return ;
	}
	if(st>minst) return;
	for(int i=p+2;i<=v;i++)
		if(x[i]-x[p]<=d)
			dfs(v,i,st+1);
	dfs(v,p+1,st+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	casenum=read<int>();T=read<int>();
	while(T--){
		n=read<int>();d=read<ll>();ans=0;
		for(int i=1;i<=n;i++) x[i]=read<ll>();
		for(int i=1;i<=n;i++)
			for(int j=i+3;j<=n;j++){
				minst=n;
				mincnt=0;
				dfs(j,i,0);
				if(mincnt==2) ans++;
			}
		printf("%d\n",ans);
	}
}
