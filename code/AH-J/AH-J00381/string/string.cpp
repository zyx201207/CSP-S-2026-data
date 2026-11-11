#include<bits/stdc++.h>
using namespace std;
int n;
int p[200010];
char q[200010];
long long sum=0;
int l,r;
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	map<long long,char>x;
	scanf("%d",&n);
	if(n==1)return puts("0"),0;
	if(n==2)
	{
		int x,y;
		char a,b;
		cin>>x>>a>>y>>b;
		if(a==b)return puts("0"),0;
		else return printf("%d",min(x,y)),0;
	}
	int t=0;
	for(int i=1;i<=n;i++)cin>>p[i]>>q[i];
	bool f=0;
	for(int i=2;i<=n;i++)
	if(q[i]!=q[i-1])
	{
		f=1;
		break;
	}
	if(f==0)return puts("0"),0;
	//for(int i=1;i<=t;i++)cout<<x[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=p[i];j++)
		x[++t]=q[i];
		sum+=p[i];
	}
	l=sum/2;
	if(sum%2==0)r=l+1;
	else r=l+2;
	while(l>0 and r<=sum)
	{
		if(x[l]!=x[r])ans++;
		l--,r++;
	}
	printf("%lld",ans);
	return 0;
}
