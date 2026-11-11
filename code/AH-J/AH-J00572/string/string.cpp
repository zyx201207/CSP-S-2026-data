#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[200005],b[200005];
string str[200005],str2[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i]>>str[i];
		b[n-i+1]=a[i];
		str2[n-i+1]=str[i];
	}
	//for(int i=1;i<=n;i++) cout<<i<<":"<<b[i]<<' '<<str2[i]<<'\n';
	for(int i=1,j=1;i<=n;)
	{
		if(str[i]!=str2[j])
		{
			long long t=min(a[i],b[j]);
			ans+=t;
			a[i]-=t;
			b[j]-=t;
			//cout<<i<<' '<<j<<' '<<a[i]<<' '<<b[j]<<' '<<ans<<'\n'; 
			if(a[i]==0) i++;
			if(b[j]==0) j++;
		}
		else
		{
			long long t=min(a[i],b[j]);
			a[i]-=t;
			b[j]-=t;			
			//cout<<i<<' '<<j<<' '<<a[i]<<' '<<b[j]<<' '<<ans<<'\n'; 
			if(a[i]==0) i++;
			if(b[j]==0) j++;
		}
	}
	cout<<ans/2;
	return 0;
}
