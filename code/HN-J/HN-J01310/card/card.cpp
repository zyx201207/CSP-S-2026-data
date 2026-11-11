#include<bits/stdc++.h>
using namespace std;
int n,m,pos;
int a[500010],b[500010],c[30010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
    	memset(b,0,sizeof(b));
    	int cnt=1;
    	for(int j=i;j<=n;j++)
    	{
    		bool flag=false;
    		for(int k=1;k<=cnt;k++)
		    {
			    if(b[k]==a[j])
			    {
				    flag=true;
				    pos=k;
				    break;
			    }  
		    }
		    if(flag)
		    {
			    for(int k=pos;k<=cnt;k++)
			        b[k]=0;
			    cnt=pos;
			    b[cnt]=a[j];
			    cnt++;
		    }
		    else
		    {
		    	b[cnt]=a[j];
		    	cnt++;
			}     
		}
		for(int k=1;k<=m;k++)
		{
			for(int j=1;j<=cnt;j++)
		    {
	    		if(b[j]==k)
	    		{
	     			c[k]++;
	    			break;
    			}
    		}
		}
	}
	for(int i=1;i<=m;i++)
	    cout<<c[i]<<" ";
    return 0;
}
