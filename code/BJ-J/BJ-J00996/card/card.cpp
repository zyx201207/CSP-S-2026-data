#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
stack<int>s;
int a[N],ans[N],h[N],b[N],t[N],lst[N],bs[N];
bool v[N];
int n,m;
bool check_a()
{
	for(int i=2;i<=n;i++)
		if(a[i-1]>a[i])
			return 0;
	return 1;
}
void work(int len)
{
	for(int i=1;i<=len;i++)
	{
		for(int j=i;j<=len;j++)
		{
			if(!h[b[j]])
				s.push(b[j]),h[b[j]]++;
			else
				while(s.top()!=b[j])
				{
					h[s.top()]--;
					s.pop();
				}
		}
		while(!s.empty())
		{
			ans[s.top()]+=t[i],h[s.top()]--;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;//Trick||Treat!
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n<=5000&&m<=3000)//5000 3000
	{
		for(int i=1;i<=n;i++)
			b[i]=a[i],t[i]=1;
		work(n);
		return 0;
	}
	if(check_a())
	{
		for(int i=n;i>=1;i--)
		{
			if(!v[a[i]])
			{
				v[a[i]]=1;
				h[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++)
			cout<<h[i]<<" ";
		return 0;
	}
	if(m<=2)
	{
		if(m==1)
		{
			cout<<n;
			return 0;
		}
		int ans1=0,ans2=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[n])
			{
				if(a[i]==1)
					ans1++;
				else
					ans2++;
			}
			else
				ans1++,ans2++;
		}
		cout<<ans1<<" "<<ans2;
		return 0;
	}
	int tot=0,cnt=1;
	b[++tot]=a[1];
	for(int i=2;i<=n;i++,cnt++)
		if(a[i]!=a[i-1])
		{
			t[tot]=cnt;
			b[++tot]=a[i];
			cnt=0;
		}
	t[tot]=cnt;
/*
5 3
1 3 3 2 2
*/
	//for(int i=1;i<=tot;i++)
	//	cout<<t[i]<<" ";
	//cout<<"\n";
	if(tot<=10000)//10000
	{
		work(tot);
		return 0;
	}
	for(int i=1;i<=n;i++)
		bs[a[i]]++;
	for(int i=1;i<=n;i++)
		lst[a[i]]=i;
	for(int i=1;i<=m;i++)
	{
		for(int j=lst[i];j<=n;j++)
		{
			if(!h[a[j]])
				s.push(a[j]),h[a[j]]++;
			else
				while(s.top()!=a[j])
				{
					h[s.top()]--;
					s.pop();
				}
		}
		while(!s.empty())
		{
			ans[s.top()]+=bs[i],h[s.top()]--;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}





