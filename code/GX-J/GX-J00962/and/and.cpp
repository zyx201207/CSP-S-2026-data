#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

long long n,m,a[200010],cnt=-1;
bool cmp(int x,int y)
{
		return x>y;
}
int main()
{
		freopen("and1.in","r",stdin);
		freopen("and1.answer","w",stdout);
		scanf("%lld %lld",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		sort(a+1,a+n+1,cmp);
		if(m==1) {printf("%lld",a[1]); return 0;}
		for(int i=1;i<=n;i++) 
		{
				long long ans=a[i],flag=1;
				for(int j=1;j<=n;j++){
					long long x=(ans&a[j]);
					if(x==0||i==j) continue;
					else {ans=x;flag++;}
					if(flag==m) {cnt=max(cnt,ans);break;}}
		}
		printf("%lld",cnt);
		return 0;
}
