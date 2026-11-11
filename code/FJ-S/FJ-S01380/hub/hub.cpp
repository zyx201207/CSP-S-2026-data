#include<bits/stdc++.h>
#define MAXN 2000005

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

int c,t,n,k,u,v;
vector<int> edge[MAXN];

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	c=_r(),t=_r();
	while(t--){
		n=_r(),k=_r();
		for(int i=1;i<=n;i++) edge[i].clear();
		for(int i=1;i<n;i++){
			u=_r(),v=_r();
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		
		if(c==13 || c==14){
			int m=(n-1)/2,ans;
			if(k==n) ans=0;
			else if(k>=m) ans=1;
			else{
				int dd=ceil(1.00*(m-k)/4.00);
				ans=dd+1;
			}
			_w(ans,'\n');
			continue;
		}
	}
	
	return 0;
}
