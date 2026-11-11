#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
long long l=1,r,L=1,R,ans;
struct cc
{
	int num;
	char c;
}a[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	  cin>>a[i].num>>a[i].c;
	R=n;
	r=a[R].num;
	while(L<R)
	{
	  int m=min((a[L].num-l+1),r);
	  if(a[L].c!=a[R].c)
	    ans+=m;
	  l+=m;
	  if(l>a[L].num)
	  {
	  	l-=a[L].num;
		L++;
  	  }
	  r-=m;
	  if(r<1)
	  {
		  R--;
		  r+=a[R].num;
	  }
	}
	cout<<ans;
	return 0;
}
