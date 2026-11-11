#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,m;
const int N=5e5+5;
const int M=3e5+5;
int a[N];
int cnt[M];
int arr[N];
int ans[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=m+1;i<=n;i++)
    {
    	cnt[i]=1;
    }
    memset(arr,0,sizeof(arr));
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	cnt[a[i]]=i;
    	arr[a[i]]++;
  
     
    }
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=m;i++)
    {
    
    	if(arr[i]==1)
    	{
    		bool b[M];
    	     memset(b,0,sizeof(b));
    		for(int j=i;j<=n;j++)
    		{
    		
    			if(b[a[j]]==0)
    	    	{
    	    	    b[a[j]]=1;
    		        ans[a[j]]++;
    		    }
    		}
    	}
    	
        else
    	{
    	    bool b[M];
    	     memset(b,0,sizeof(b));
    	    for(int j=cnt[i];j<=n;j++)
    	    {
    	    
    	    	if(b[a[j]]==0)
    	    	{
    	    	    b[a[j]]=1;
    		        ans[a[j]]++;
    		    }
    	    }
        }
       
    }
    for(int i=m+1;i<=n;i++)
    {
    	bool b[M];
    	     memset(b,0,sizeof(b));
    		for(int j=i;j<=n;j++)
    		{
    		
    			if(b[a[j]]==0)
    	    	{
    	    	    b[a[j]]=1;
    		        ans[a[j]]++;
    		    }
    		}
    }
    for(int i=1;i<=m;i++)
    cout<<ans[i]<<" ";
}
