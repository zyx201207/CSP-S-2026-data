#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout)	;
	int n;
	long long ans=0;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		char ch;
		sum+=a[i];
		cin>>ch;
		b[i]=ch-'a'+1;
	}
	for(int i=1;i<=n/2;i++)
	{
		if(a[i]==a[n-i+1])
		{
			if(b[i]!=b[n-i+1]) ans+=a[i];
		}
		else if(a[i]>a[n-i+1]) 
		{
			if(b[i]!=b[n-i+1]) 
			{
				ans+=a[i];
				long long h=a[i]-a[n-i+1];
				for(int j=n-i;j>=n/2+1;j--)
				{
					if(a[j]>h) {a[j]-=h; break;}
					else {h-=a[j];n--;}
				}
			} 
			else {
				long long h=a[i]-a[n-i+1];
				for(int j=n-i;j>=n/2+1;j--)
				{
					if(a[j]>h) {a[j]-=h; break;}
					else {h-=a[j]; n--;} 
 				}
			}
			}
		
		else if(a[i]<a[n-i+1]) 
		{
			if(b[i]!=b[n-i+1]) 
			{
				ans+=a[n-i+1];
				long long h=a[n-i+1]-a[i];
				for(int j=i;j<=n/2+1;j++)
				{
					if(a[j]>h) {a[j]-=h; break;}
					else {h-=a[j];i++;n++;}
				}
			} 
			else {
				long long h=a[n-i+1]-a[i];
				for(int j=i;j<=n/2+1;j++)
				{
					if(a[j]>h) {a[j]-=h; break;}
					else {h-=a[j]; i++;n++;} 
 				}
			}
 				}
	}
	cout<<ans;
	
	return 0;
}
