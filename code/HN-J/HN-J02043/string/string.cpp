#include<bits/stdc++.h>

using namespace std;

long long a,s=1,d,f,g,q[200005];
char w[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>a;
	for(long long z=1;z<=a;z++)
	{
		cin>>q[z]>>w[z];
	}
	d=a;
	for(;s!=d;)
	{
		f=min(q[s],q[d]);
		if(w[s]!=w[d])
		{
			g+=f;
		}
		q[s]-=f;
		q[d]-=f;
		if(q[s]==0)
		{
			s++;
		}
		else
		{
			d--;
		}
	}
	cout<<g;
	
	return 0;
} 
