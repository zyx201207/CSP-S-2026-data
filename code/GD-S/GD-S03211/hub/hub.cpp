#include<bits/stdc++.h>
using namespace std;
int main()
{
 	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);		
    long long c,t,n[100000],k[100000],x[10000][10000],y[10000][10000],mix;
    cin>>c>>t;
    for(int i=0;i<t;i++)
    {
    	cin>>n[i]>>k[i];
    	
    		for(int j=0;j<n[i]-1;j++)
    		{
    			cin>>x[i][j]>>y[i][j];
			}
		
	}for(int i=0;i<t;i++)
    {
    	mix=99999999;
    		for(int j=0;j<n[i]-1;j++)
    		{
    		if(y[i][j]==k[i]&&y[i][j]-x[i][j]<mix)mix=y[i][j]-x[i][j];
			}
		if(mix==99999999)mix=1;
		else if(mix<0)mix=-mix;
		cout<<mix<<"\n";
	}
	return 0;
 } 
 

