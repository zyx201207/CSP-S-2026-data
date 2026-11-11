#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 500050 ;

int ans=1,n;

ll de[MAXN],m,a[MAXN];

inline ll read()
{
	register ll res=0ll,flag=1ll;
	char ch;
	while((ch=getchar())<'0' || ch>'9')if(ch = '-')flag=-1;
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res*flag;
}

inline bool isOK(int now,int targ)
{
	ll na=0;
	if(now<targ)return false;
	for( ; targ ; targ--,now--)na+=de[now]*targ;
	if(na<=m)return true;
	else return false;
}

int main()
{
	freopen("crystal.in", "r" ,stdin);
	freopen("crystal.out", "w" , stdout);
	
	n=read(),m=read();
	for(int i=0;i<n;i++)a[i]=read();
	sort(a,a+n);
	for(int i=1;i<n;i++)de[i]=a[i]-a[i-1];
	for(int i=1;i<n;i++)
	{
		if(isOK(i,ans))ans++;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}