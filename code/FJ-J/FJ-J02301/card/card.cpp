#include<bits/stdc++.h>
using namespace std;
int n,m,a[500000],b[300000],s=0,h[300000];
int f(int p)
{
	s=p;
	for(int c=p;c<n;c++)
	{
		b[s]=a[c];
		s++;
		for(int q=p;q<s;q++)
	    {
		    if(b[q]==a[c+1])
		    {
		   	    s=q;
		    }
	    }   
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];  
	}
	for(int i=0;i<n;i++)
	{  
		f(i);
	    for(int w=i;w<s;w++)
	    {
		    for(int p=1;p<=m;p++)
	        {
		        if(b[w]==p)
		            h[p]++;
		    }
	    }  
	}
	for(int i=1;i<=m;i++)
	{
		cout<<h[i]<<" ";  
	}
	return 0;
}