#include<bits/stdc++.h>
#define MAXM 500005
#define MAXN 505
#define int long long

using namespace std;
namespace FastIO
{
	inline string _rs()
	{
		string str="";
		int ch=getchar();
		while(ch==' ' || ch=='\n' || ch=='\r') ch=getchar();
		while(ch!=' ' && ch!='\n' && ch!='\r' && ch!=EOF){
			str.push_back(ch);
			ch=getchar();
		}
		return str;
	}
	inline void _ws(string a,char b)
	{
		int len=a.size();
		for(int i=0;i<len;i++) putchar(a[i]);
		putchar(b);
		return ;
	}
	inline int _r()
	{
		int flag=1,ans=0,ch=getchar();
		while((ch<'0' || ch>'9') && ch!=EOF){
			if(ch=='-') flag=-1;
			ch=getchar();
		}
		while(ch>='0' && ch<='9'){
			ans=(ans<<1)+(ans<<3)+(ch^48);
			ch=getchar();
		}
		return flag*ans;
	}
	inline void _w(int a,char b)
	{
		if(a<0) a=-a,putchar('-');
		int sta[22],top=0;
		do{
			sta[top++]=a%10;
			a/=10;
		}while(a);
		while(top) putchar(sta[--top]+48);
		putchar(b);
		return ;
	}
}
using namespace FastIO;

struct node{int a,t;};
vector<node> sub[MAXN],stat[MAXM];
int c,n,m,d,q,w[MAXM],k,a,t,x,y,floyd[MAXN][MAXN];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=_r(),n=_r(),m=_r(),d=_r(),q=_r();
	for(int i=1;i<=m;i++) w[i]=_r();
	for(int i=1;i<=n;i++){
		k=_r();
		for(int j=1;j<=k;j++){
			a=_r(),t=_r();
			sub[i].push_back((node){a,t});
			stat[a].push_back((node){i,t});
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) floyd[i][j]=LONG_LONG_MAX/3;
		}
	}
	for(int i=1;i<=m;i++){
		int len=stat[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				int u=stat[i][j].a,v=stat[i][k].a;
				floyd[u][v]=floyd[v][u]=min(floyd[u][v],stat[i][j].t+stat[i][k].t);
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		x=_r(),y=_r();
		int ans=LONG_LONG_MAX;
		int lenX=stat[x].size(),lenY=stat[y].size();
		for(int j=0;j<lenX;j++){
			for(int k=0;k<lenY;k++){
				int u=stat[x][j].a,v=stat[y][k].a;
				ans=min(ans,floyd[u][v]+stat[x][j].t+stat[y][k].t);
				//cout<<"    u="<<u<<" v="<<v<<" d="<<floyd[u][v]<<" du="<<stat[x][j].t<<" dv="<<stat[y][k].t<<endl;////////////////
			}
		}
		_w(ans+w[x]+w[y],'\n');
	}
	
	return 0;
}
