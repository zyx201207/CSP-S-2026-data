#include <bits/stdc++.h>
using namespace std;
struct s{
	long long num;
	int leng;
	string s1,z;
}a[200010];
int n,m;
long long ans=INT_MAX;
bool cmp(const s &a,const s &b)
{
	if(a.leng!=b.leng) return a.leng>b.leng;
	return a.z>b.z;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].num,a[i].s1="",a[i].z="";
    for(int i=1;i<=n;i++)
    {
		long long x=a[i].num;
		int t=0;
		while(x!=0)
		{
			int f=x%2;
			if(f==0) a[i].s1[t]='0';
			else if(f==1) a[i].s1[t]='1';
			x/=2;
			t++;
		}
		a[i].leng=t;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<a[i].leng;j++)
		{
			a[i].z[j]=a[i].s1[a[i].leng-j-1];
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++) ans&=a[i].num;
	cout<<ans;
    return 0;
}
