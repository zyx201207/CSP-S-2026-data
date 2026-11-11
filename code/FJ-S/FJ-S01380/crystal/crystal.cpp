#include<bits/stdc++.h>
#define MAXN 500005
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

int n,m,a[MAXN],sum[MAXN],ans;

bool cmp(int a,int b){return a>b;}

int find(int st)
{
	int l=st+1,r=n,mid;
	while(l<=r){
		mid=l+(r-l)/2;
		int L=mid-st,sum1=a[st]*L-(sum[mid]-sum[st]);
		if(sum1<=m) l=mid+1;
		else r=mid-1;
	}
	return r;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=_r(),m=_r();
	for(int i=1;i<=n;i++) a[i]=_r();
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	
	a[0]=LONG_LONG_MIN;
	int cnt=1;
	for(int i=1;i<=n;i++){
		if(a[i+1]==a[i]) cnt++;
		else{
			int ret=find(i);
			ans=max(ans,cnt+ret-i);
			cnt=1;
		}
	}
	_w(ans,'\n');
	
	return 0;
}
