#include<bits/stdc++.h>

using namespace std;
long long maxx=INT_MIN;
struct node{
	long long num;
	string bin;
}a[200005]; 
string dtob(long long num){
	string ans="";
	while(num>0)
	{
		ans.append(to_string(num%2));
		num/=2;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int n,m;
bool cmp(node a,node b)
{
	if(a.bin==b.bin)
		return 1;
	if(a.bin.size()>b.bin.size())
		return 1;
	if(a.bin.size()<b.bin.size())
		return 0;
	for(int i=0;i<a.bin.size();++i)
	{
		if(a.bin[i]=='1'&&b.bin[i]=='0')
			return 1;
		if(a.bin[i]=='0'&&b.bin[i]=='1')
			return 0; 
	}
}
int main()
{
	freopen("and.in",".r",stdin);
	freopen("and.out",".w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i].num);
		a[i].bin=dtob(a[i].num) ;
		maxx=max(maxx,a[i].num);
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	if(m==n)
	{
		long long ans=a[1].num;
		for(int i=2;i<=m;++i)
			ans=ans&a[i].num;
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		long long maxn=INT_MIN;
		for(int i=1;i<=n;++i)
		{
			for(int j=2;j<=n;++j)
			{
				if(i!=j) 
					maxn=max(maxn,a[i].num&a[j].num);
				
			}
		}
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	long long ans=a[1].num;
	for(int i=2;i<=m;++i)
		ans=ans&a[i].num;
	cout<<ans;
	return 0;
}












