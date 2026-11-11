#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-48;
		ch=getchar();
	}
	return x*f;
}
const int N=510,M=5e5+10,K=151;
vector<int> mp[N],mpt[M];
signed t[N][M];
int c,d,q,n,m;
int w[M],minn[M];
int k,tmp,xr,yr,cnt;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		k=read();
		for(int j=1;j<=k;j++){
			tmp=read();
			mp[i].push_back(tmp);
			t[i][tmp]=read();
			mpt[tmp].push_back(i);
		}
	}
	while(q--){
		memset(minn,0x3f3f,sizeof(minn));
		xr=read(),yr=read();
		cnt=w[xr]+w[yr];
		minn[xr]=0;
		queue<int> st;
		st.push(xr);
		while(!st.empty()){
			int pos=st.front();
			st.pop();
			for(auto x:mpt[pos]){
				for(auto p:mp[x]){
					if(mpt[p].size()==1&&p!=xr&&p!=yr)continue;
					if(minn[p]>minn[pos]+t[x][pos]+t[x][p]){
						minn[p]=minn[pos]+t[x][pos]+t[x][p];
						if(minn[p]>minn[yr])continue;
						st.push(p);
					}
				}
			}
		}
		cout<<cnt+minn[yr]<<'\n';
	}
	return 0;
}
