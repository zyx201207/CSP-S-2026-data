#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[200005],arr[200005],tmp[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int cnt=n,cnt1=0;
    for(int i=0;i<n;i++)
    {
    	tmp[i]=a[i];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<cnt-1;j++)
        {
            arr[j]=tmp[j]&tmp[j+1];
        }
        for(int j=0;j<cnt-1;j++)
        {
            tmp[j]=arr[j];
        }
        cnt--;
        cnt1++;
    }
    int ans=arr[0];
    for(int i=1;i<cnt1-1;i++)
    {
    	if(ans<arr[i])
    	{
    	    ans=arr[i];
    	}
    }
    cout<<ans;
    return 0;
}