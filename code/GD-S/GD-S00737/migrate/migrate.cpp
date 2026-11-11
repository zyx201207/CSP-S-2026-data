#include<bits/stdc++.h>
using namespace std;
char ch[1<<20],*P,*Q;
#define gc() (((P==Q&&(P=(Q=ch)+fread(ch,1,1<<20,stdin))),P==Q)?EOF:*Q++)
#define int long long
inline int read(){
	int res=0;bool sign=false;char c=gc();
	for(;!isdigit(c);c=gc()) if(c=='-') sign=true;
	for(;isdigit(c);c=gc()) res=res*10+c-'0';
	return sign?-res:res;
}
int n,d,c,t,x[2000005],ans=0,anss=0;
void dfs(int pos,int to,int w){
	if(w>ans) return;
	if(pos==to){
		if(w<ans) ans=w,anss=0;
		if(w==ans) anss++;
		return;
	}
	if(w>n) return;
	for(int i=1;i<=n;i++) if(i!=pos&&abs(x[i]-x[pos])<=d) dfs(i,to,w+1);
}
signed main(void){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;i++) x[i]=read();
		int outs=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				ans=21474836,anss=0,dfs(i,j,0),outs+=(anss==2);
			}
		cout<<outs<<"\n";
	}
	return 0; 
}
