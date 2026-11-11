#include<bits/stdc++.h>
using namespace std;
long long n,ans,shu,a; 
char c;
string p,q;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>shu>>c;
		a+=shu;
		for(long long j=0;j<shu;j++) 
		{
			p+=c;
			q=c+q; 
		}
	}
	for(int i=0;i<n;i++)
	{
		if(p[i]!=q[i]) 
		{
			ans++;
			q[i]=p[i];
			p[n-i+1]=q[i];
			//cout<<p<<' '<<q<<endl;
		}
	}
	cout<<ans; 
	return 0;
}
