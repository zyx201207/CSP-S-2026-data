#include<bits/stdc++.h> 
using namespace std;
bool cmp1(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a;
	long long csa;
	cin>>a>>csa;
	long long z[a];
	for(int i=0;i<a;i++)
	{
		cin>>z[i];
	}
	sort(z,z+a,cmp1);
	int khc[a];	
	for(int x=0;x<a;x++)
	{
	    int yddz=0;
		int zjj=z[x];
		int cs=csa;
	    for(int i=0;i<=x;i++)
	    {	
	    	if(cs>=zjj-z[i])
	    	{
	    		cs=cs+z[i]-zjj;
			    yddz++;	
     	    }
     	    else
			{
				break;
			}
	    	
    	}
        khc[x]=yddz;
	}
	sort(khc,khc+a,cmp1);
	cout<<khc[a-1];
	return 0;
}
