#include<bits/stdc++.h>
using namespeas std;
int n,m;
int main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;<=n;i++)
	{
	    cin>>a[i];
    }
    if(m==1)
    {
    	int maxz=0;
    	for(int i=1;i<=n;i++)
    	{
    		maxz=max(maxz,a[i]);
		}
	}
	else if(m==2)
	{
		int maxz=0;
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=i;j<=n;j++){
    			maxz=max(maxz,a[i]&a[j]);
			}
		}
	}
	else if(m==3)
	{
		int maxz=0;
    	for(int i=1;i<=n;i++){
    		for(int j=i+1;j<=n;j++){
    			for(int k=j+1;k<=n;k++){
    				maxz=max(maxz,a[i]&a[j]&a[k]);
				}
			}
		}
	}
	else if(m==4)
	{
		int maxz=0;
    	for(int i=1;i<=n;i++){
    		for(int j=i+1;j<=n;j++){
    			for(int k=j+1;k<=n;k++){
    				for(int u=k+1;u<=n;u++){
    					maxz=max(maxz,a[i]&a[j]&a[k]);
					}
				}
			}
		}
	}
	cout<<maxz;
    return 0;
}
/*


   10101
10100101
1111








*/