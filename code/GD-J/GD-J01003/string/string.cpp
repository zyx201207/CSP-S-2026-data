#include<bits/stdc++.h>
const int N=3e5+10;
using namespace std;
int n;
long long a[N];
long long s1,ans,s2;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int j=n,i=1;
	s1=a[1];
	s2=a[n];
	while(i<j)
	{
		if(s1>s2)
		{
			s1-=s2;
			if(c[i]!=c[j]) ans+=s2;	 
			j--;
			s2=a[j];
		}
		else if(s1<s2)
		{
			s2-=s1;
			if(c[i]!=c[j]) ans+=s1;
			i++;
			s1=a[i];
		}
		else 
		{
			if(c[i]!=c[j]) ans+=s1;
			i++;
			j--;
			s1=a[i];
			s2=a[j];
		}
	}
	cout<<ans;
	return 0;
}
