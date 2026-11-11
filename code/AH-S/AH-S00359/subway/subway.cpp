#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=505,M=(5e5+5),INF=LLONG_MAX/3;
LL c,n,d,m,q,f[N][N],w[M],k[N];
struct S{
    LL v,w;
    S(LL v,LL w):v(v),w(w){}
};
vector<S>G[M];//,A[N];
inline LL read(){
	LL ans=0,neg=1;
	char c=getchar_unlocked();
	while(c==' '||c=='\n'||c=='\r'){c=getchar_unlocked();}
	if(c=='-')
	{neg=-1;c=getchar_unlocked();}
	while(c>='0'&&c<='9'){ans=ans*10+LL(c-'0');c=getchar_unlocked();}
	return ans*neg;
}
int main(){
   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)
    {
        w[i]=read();
    }
    for(int i=1;i<=n;i++)
    {
        f[i][i]=0;
        k[i]=read();
    //    A[i].reserve(k[i]+1);
        for(int j=1;j<=k[i];j++)
        {
            LL vv=read(),ww=read();
            G[vv].emplace_back(i,ww);
     //       A[i].emplace_back(vv,ww);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            LL uu=G[i][j].v,w1=G[i][j].w;
            for(int k=0;k<j;k++)
            {
                LL vv=G[i][k].v,w2=G[i][k].w;
                f[uu][vv]=min(f[uu][vv],w1+w2);
                f[vv][uu]=min(f[vv][uu],w1+w2);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
//    for(int i=1;i<=n;i++)
  //  for(int j=1;j<=n;j++)
    //    cerr<<i<<" "<<j<<" "<<f[i][j]<<endl;
    for(int i=1;i<=q;i++)
    {
        LL x=read(),y=read(),ans=INF;
        for(int j=0;j<G[x].size();j++)
        {
            LL uu=G[x][j].v,w1=G[x][j].w;
            for(int k=0;k<G[y].size();k++)
            {
                LL vv=G[y][k].v,w2=G[y][k].w;
          //      cerr<<i<< " " <<j<< " " <<k<< " " <<uu<< " " <<vv<< " " <<w1<<" "<<w2<<" "<<w[x]<<" "<<w[y]<<endl;
                ans=min(ans,f[uu][vv]+w[x]+w[y]+w1+w2);
            }
        }
        printf("%lld\n",ans);
    }
	return 0;
}
