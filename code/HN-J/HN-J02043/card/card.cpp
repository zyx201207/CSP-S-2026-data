#include<bits/stdc++.h>

using namespace std;

long long a,s,d,q[500005],w[300005],e[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>a>>s;
	for(long long z=1;z<=a;z++)
	{
		cin>>q[z];
	}
	
	for(long long z=1;z<=a;z++)
	{
		d=1;
		for(long long x=z;x<=a;x++) 
		{
			for(long long c=1;c<d;c++)
			{
				if(q[x]==w[c])
				{
					d=c;
					break;
				}
			}
			w[d]=q[x];
			d++;
		}
		for(long long x=1;x<d;x++)
		{
			e[w[x]]++;
		}
	} 
	
	for(long long z=1;z<=s;z++)
	{
		cout<<e[z]<<' ';
	}
	
	return 0;
} 
