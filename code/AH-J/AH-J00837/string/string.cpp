#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    long long sum=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int id1=0,id2=n-1;
	long long ans=0;
	for(long long i=1,j=sum;i<j-1;)
	{
		if(c[id1]==c[id2])
		{
			if(a[id1]==a[id2])
			{
				i+=a[id1];
				j-=a[id2];
				id1++;
				id2--;
			}	
			else if(a[id1]<a[id2])
			{
				i+=a[id1];
				j-=a[id1];
				a[id2]-=a[id1];
				id1++;
			}
			else
			{
				i+=a[id2];
				j-=a[id2];
				a[id1]-=a[id2];
				id2--;
			}
		}
		else
		{
			if(a[id1]==a[id2])
			{
				i+=a[id1];
				j-=a[id2];
				id1++;
				id2--;
				ans+=a[id1];
			}	
			else if(a[id1]<a[id2])
			{
				i+=a[id1];
				j-=a[id1];
				a[id2]-=a[id1];
				ans+=a[id1];
				id1++;
			}
			else
			{
				i+=a[id2];
				j-=a[id2];
				a[id1]-=a[id2];
				ans+=a[id2];
				id2--;
			}
		}
	}
	cout<<ans;
    return 0;
}
