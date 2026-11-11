#include<bits/stdc++.h>
using namespace std;
long long a[100],b[100],c[100],s[200005]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,h=0,hh=0,hhh=0,j,k,ww,l,o,w;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&s[i]);
	}
	for(int i=1;i<=n;i++)
	{
	    j=1;
	    for(k=1;k<=90;k++)
	    {
	    	a[k]=0;
	    	b[k]=0;
		}
		ww=s[i];
	    while(ww>0)
	    {
		    b[j]=ww%2;
		    ww/=2;
		    j++;
	    }
	    for(l=i+1;l<=n;l++)
	    {
		    o=1;
		    hh=0;
		    w=s[l];
		    while(w>0)
		    {
		 	    a[j]=w%2;
			    w/=2;
			    if(a[o]==b[o]) hh++;
		   	    o++;
	    	}
		    if(m>2)
		    {
		    	for(l=i+1;l<=n;l++)
	            {
		            o=1;
		            hh=0;
		            w=s[l];
		            while(w>0)
		            {
		 	            c[j]=w%2;
			            w/=2;
			            if(c[o]==b[o]||c[o]==a[o]) hh++;
		   	            o++;
		   	        }
	    	    }
		    }
		    h=max(h,hh); 
		}
		hhh=max(hhh,h);
	}
	cout<<h; 
	fclose(stdin);fclose(stdout);
	return 0;
} 
