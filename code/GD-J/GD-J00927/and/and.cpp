#include<bits/stdc++.h>
using namespace std;
string a[200010];
bool f[200010];
int w=0;
void func(int n,int j)
{
	string s="";
	while(n!=0)
	{
		int l = n%2;
		s+=(l+'0');
		n/=2;
	}
	w = max(w,(int)s.size());
	for(int i=s.size()-1;i>=0;i--)
	{
		a[j] += s[i];
	}
}
bool cmp(string a,string b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		func(k,i);
		f[i] = true;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i].size()<w)
		{
			int l = w-a[i].size();
			for(int j=1;j<=l;j++)
			{
				a[i] = '0'+a[i];
			}
		} 
	} 
	sort(a,a+n,cmp);
	int d=n;
	int ans=0;
	for(int i=0;i<w;i++)
	{
		int cnt=0,j=-1;
		int k=0;
		while(j<n)
		{
			j++;
			if(f[j] == false) continue;
			if(a[j][i] == '1')
			{
				k++;
			}
		}
		j=0;
		while(j<n && d>m)
		{
			j++;
			if(f[j] == false) continue;
			if(a[j][i] == '0' && k>=m)
			{
				f[j] = false;
				d--;
			}
		}
		ans*=2;
		if(k>=m) ans+=1;
	}
	cout<<ans;
	return 0;
} 
