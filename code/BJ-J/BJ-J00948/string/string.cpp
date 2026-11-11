#include<iostream>
#include<cstdio>
using namespace std;
long a[200005];
char c[200005],s[999999999];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    	sum+=a[i];
    	cin>>c[i];
    	for(int j=0;j<a[i];j++)
    	{
    	    s[j]=c[i];
    	}
    }
    int half=sum/2;
    int ans=0;
    for(int i=0;i<half;i++)
    {
    	if(s[i]!=s[sum-1-i])
    	{
    	    ans++;
    	}
    }
    cout<<ans;
    return 0;
}