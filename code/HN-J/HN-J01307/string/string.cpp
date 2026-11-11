#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
struct edge{
	long long s;
	char w;
}m[N];
long long n,p,maxn=0,x=0;
char k[N];
long long c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int w=0,l=0;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i].s>>m[i].w;		
		c[int(m[i].w)-96]+=m[i].s;
		p+=m[i].s;
		if(m[i].s>=1000000000)
		{
			continue;
			l=1;
		}
		for(int j=w+1;j<=w+m[i].s;j++)k[j]=m[i].w;		
		w+=m[i].s;		
	}

	int o=0;
	for(int i=1;i<=26;i++)
	{	
		
		if(c[i]>=maxn && maxn==0)o=i;
		else if(c[i]>maxn)o=i;
		maxn=max(c[i],maxn);
	}
	if(l==1)
	{
		if(p%2==0)cout<<p-maxn;
		else cout<<p-maxn-1;
	}	
	for(int i=1;i<=(p+1)/2;i++)
	{
		if(k[i]==k[p-i+1] && k[i]!=char(o+96))x++;
	}
	if(p%2==0)cout<<p-maxn-x;
	else cout<<p-maxn-x;
	
	
	





	return 0;
}

