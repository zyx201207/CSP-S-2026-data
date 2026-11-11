#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
inline int kd()
{
	char ca=getchar();
	bool fffff=true;
	int res=0;
	while(ca<'0'||ca>'9')
	{
		if(ca=='-') fffff=false;
		ca=getchar();
	}
	while(ca>='0'&&ca<='9') res=(res<<1)+(res<<3)+(ca^'0'),ca=getchar();
	return (fffff?res:-res);
}
int n,m,ans;
int a[N];
vector<int> v[35];
void to2(int x)
{
	int len=1,tmp=x;
	while(x)
	{
		if(x%2) v[len].push_back(tmp);
		x/=2;
		len++;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=kd(),m=kd();
	for(int i=1;i<=n;i++) a[i]=kd();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) to2(a[i]);
	int lst=30;
	while(1)
	{
		bool f=false;
		for(int i=lst-1;i>=1;i--)
		{
			int l=v[i].size();
			if(l==m)
			{
				ans=v[i][0];
				for(int j:v[i]) ans&=j;
				printf("%d",ans);
				return 0;
			}
			if(l>m)
			{
				lst=i;
				f=true;
				n=0;
				for(int j:v[i]) a[++n]=j;
				for(int j=1;j<=30;j++) v[j].clear();
				ans=a[1];
				for(int j=1;j<=n;j++) to2(a[j]),ans&=a[j];
				break;
			}
		}
		if(!f)
		{
			printf("%d",ans);
			return 0;
		}
	}
	return 0;
}
