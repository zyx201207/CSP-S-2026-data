#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
long long ans;
char s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
	   cin>>a[i]>>s[i];
	   a[i]+=a[i-1];
	}
    long long i=1,j=n,x=0,y=a[n]+1;
    cout<<x<<" "<<y<<endl;
	while(i<j)
	{
		if(a[i]==a[n]-a[j-1])
		{
			if(s[i]!=s[j]) ans+=a[i]-x;
			x=a[i];
			y=a[j-1]+1;
			i++;
			j--;
		}
		else if(a[i]<a[n]-a[j-1])
		{
			if(s[i]!=s[j]) ans+=a[i]-x;
			y-=(a[i]-x);
			x=a[i];
			i++;
		}
		else if(a[i]>a[n]-a[j-1])
		{
			if(s[i]!=s[j]) ans+=y-(a[j-1]+1);
			x+=(y-(a[j-1]+1));
			y=a[j-1]+1;
			j--;
		}
		cout<<x<<" "<<y<<endl;
	}
	cout<<ans;
	return 0;
}
