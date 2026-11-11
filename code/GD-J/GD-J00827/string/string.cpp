//string

#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],num=0,ans=0;
char c;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c;
		num+=a[i];
		s+=c;
	}
	num/=2;
	int l=0,r=s.size()-1,e=s.size();
	while(e>1)
	{
		
		if(s[l]!=s[r]) ans+=min(a[l+1],a[r+1]);
		if(a[l+1]<a[r+1])
		{
			a[r+1]-=a[l+1];
			l++;
			e--;
		}
		else if(a[l+1]>a[r+1])
		{
			a[l+1]-=a[r+1];
			r--;
			e--;
		}
		else
		{
			l++;
			r--;
			e-=2;
		}
	}
	cout<<ans;
}
