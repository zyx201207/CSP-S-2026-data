#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    vector<char> c(n);
    char c1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
    }
    c1=c[0];
    bool flag=1;
    for(int i=1;i<n;i++)
    {
        if(c1!=c[i])
        {
        	flag=0;
		}
    }
    if(flag)
    {
    	cout<<"0";
    	return 0;
	}
    for(int i=1;i<n;i++)
    {
        b[i]=b[i-1]+a[i-1];
    }
    int len=b[n]+a[n];
    vector<char> d(len);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a[i];j++)
        {
            d[b[i]+j]=c[i];
        }
    }
    int ans=0;
    for(int i=0;i<len/2;i++)
    {
        if(d[i]!=d[len-i-1])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
