#include<bits/stdc++.h>
#define MAXN 2000005
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

int c,t,n,d,x[MAXN],nt[MAXN],vis[MAXN],cnt[MAXN],ans;
vector<int> edge[MAXN];

void bfs(int st)
{
	vis[st]=cnt[st]=1;
	for(int i=st+1;i<=n;i++) vis[i]=cnt[i]=0;
	queue<int> q=queue<int>();
	q.push(st);
	while(!q.empty()){
		int pc=q.front(); q.pop();
		for(int i=pc+1;i<=nt[pc];i++){
			if(vis[i]==0){
				vis[i]=vis[pc]+1;
				q.push(i);
			}
			if(vis[i]==vis[pc]+1) cnt[i]+=cnt[pc];
		}
	}
	
	return ;
}

int find(int st)
{
	int l=st+1,r=n,mid;
	while(l<=r){
		mid=l+(r-l)/2;
		if(x[mid]-x[st]<=d) l=mid+1;
		else r=mid-1;
	}
	return r;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	c=_r(),t=_r();
	while(t--){
		n=_r(),d=_r();
		for(int i=1;i<=n;i++) x[i]=_r();
		if(n==1){
			_w(0,'\n');
			continue;
		}
		
		if(c==11 || c==12){
			int l=x[2]-x[1];
			if((d/l)<=1) ans=0;
			else{
				int kc=min(n,(d/l)*2-1);
				ans=n-kc;
			}
			_w(ans,'\n');
			continue;
		}
		if(c==13 || c==14){
			ans=0;
			for(int i=1;i<=n;i++){
				int ret=find(i);
				if(ret==i+1) continue;
				else if(ret==i+2){
					int ret1=find(ret-1);
					ans+=ret1-ret;
				}
				else{
					int ret1=find(ret-1),ret2=find(ret-2);
					ans+=ret1-ret2;
				}
			}
			_w(ans,'\n');
			continue;
		}
		
		int p1=1;
		for(int i=1;i<=n;i++){
			while(p1+1<=n && x[p1+1]-x[i]<=d) p1++;
			nt[i]=p1;
		}
		ans=n*(n-1)/2;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++) if(cnt[j]!=2) ans--;
		}
		_w(ans,'\n');
	}
	
	return 0;
}
