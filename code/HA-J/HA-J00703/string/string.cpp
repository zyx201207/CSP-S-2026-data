#include<bits/stdc++.h> 
using namespace std;
struct c{
	int q;
	char w;
};
string e;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,z=1,v=0,d=0,r=1;
	cin>>n;
	c x[10005];
	for(int i=1;i<=n;i++)
	{
	    cin>>x[i].q>>x[i].w;
	    v+=x[i].q;
	    for(int j=1;j<=x[i].q;j++)
		{
		    s[z]=x[i].w;
		    z+=1;
	    }
	    for(int k=x[i].q;k>=1;k--)
		{
		    e[r]=x[i].w;
		    r-=1;
	    }
    }
    	    for(int k=1;k<=v;k++)
	        {
	        	if(e==s)
			    {
    	            cout<<d;
    	            return 0;
    	        }
    	        if(e[k]!=s[k])
		        {
    	            e[k]=s[k];
    	            d++;
    	        }
    	        
    	   }
    fclose(stdin);
	fclose(stdout);
	return 0;	
    }
	
	
