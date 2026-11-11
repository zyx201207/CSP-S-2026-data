#include<bits/stdc++.h>
using namespace std;
#define int long long
#define File(x) (freopen(x".in","r",stdin),freopen(x".out","w",stdout))
#define ft first
#define sd second
inline int read(){char ch=getchar();int f=1,x=0;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();return f*x;}
const int N=1e6+5,inf=1e18;
int n,d,ans;
int x[N];
int nxt[N];
void work(){
	n=read(),d=read(),ans=0;
	for(int i=1;i<=n;i++)
		x[i]=read();
	x[n+1]=inf;
	for(int i=1;i<=n;i++)
		nxt[i]=upper_bound(x+1,x+n+2,x[i]+d)-x-1;
	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++){
			vector<int>v;
			int cur=nxt[l],tag=0;
			while(cur<r){
				v.push_back(cur);
				if(nxt[cur]==cur){tag=1;break;}
				cur=nxt[cur];
			}
			if(tag)continue;
			v.push_back(r);
			for(int i=0;i<v.size()-1;i++){
				if(v[i]-1>l&&min(nxt[v[i]-1],r)==v[i+1])tag++;
				if(v[i]-2>l&&min(nxt[v[i]-2],r)==v[i+1])tag++;
			}
			if(tag==1)ans++;
		}
	cout<<ans<<"\n";
}
void clear(){
}
signed main(){
	File("migrate");
	int c_id=read(),_=read();
	while(_--)work(),clear();
	return 0;
}