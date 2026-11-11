#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[10000],k[520][1315],r[5200],r1[5200],r2[5200],x[5200],y[5200],o=0,p=99999999999;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);		
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<q;i++)
	{
		r2[i]=9111111111;
		r[i]= 9111111111;
	}
	for(int i=0;i<n;i++)
	{
		cin>>k[i][0];
		for(int j=1;j<=k[i][0]*2;j++)
		{
			cin>>k[i][j];
		}
		
	}
	for(int i=0;i<q;i++)
	{
		cin>>x[i]>>y[i];
		for(int l=0;l<n;l++)
	{
		for(int j=1;j<k[l][0]*2;j+=2)
		{
			
			if(k[l][j]==x[i]&&p>k[l][j+1])
			{
				o=1;
				
				r1[i]+=w[x[i]];
				p=k[l][j+1];
				r1[i]+=p;
            
			}
			if(o==1&&y[i]==k[l][j])
			{
				o=2;
				r1[i]+=w[y[i]];				
				r1[i]+=k[l][j+1]+k[l][j+3];
				r1[i]=r1[i]*2-w[y[i]]-k[l][j+1];
				break;
			}
		}
		
	if(r2[i]>r1[i]&&o==2){
		r2[i]=r1[i];  
	    }       	
	}o=0;	if(r[i]>r2[i])r[i]=r2[i];
	else if(r[i]==9111111111)r[i]=r1[i-1]/2+1;
}
	for(int i=0;i<q;i++)
	{
		
		cout<<r[i]<<"\n";
	}
	return 0;
 } 
 

