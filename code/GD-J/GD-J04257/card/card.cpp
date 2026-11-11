#include <bits/stdc++.h>
using namespace std;

int a[2*10^5+100];
int b[10000000000000];

int main()
{
	freopen("card.in","r",stdin) ;
	freopen("card.out","w",stdout) ;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
	{
        cin>>a[i];
	}
 
    for(int i=1;i<=m;i++){
    	for(int i=1;i<=n;i++)
    	{
            for(int j=i;i<=n;i++)
	        {
                if(a[i]==a[j]){
            	    for(int k=i;i<j;i++){
            	    	a[k]=a[k+j-i];
		            }
		    	    for(int k=j;i<=n;i++){
            	    	a[k]=0;
            	    	n=n+j-i;
                	}
		    	}
    	    }
        }
        for(int i=1;i<=n;i++){
         	b[a[i]]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]!=0)
		    cout<<b[i];
	}
	return 0;
}
