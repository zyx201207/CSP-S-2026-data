#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("subway5.in","r",stdin);
    //freopen("subway5.out","w",stdout);
    int c,n,m,d,q,x=0,y=0;
	cin>>c>>n>>m>>d>>q;
	long long a[100000];
	long long b[100000];
	long long s[100000];
	long long t[100000];
	long long e[100000];
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	int k;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>b[i]>>s[i];
		x+=b[2]*k;
		y+=s[2]*k;
	}
	for(int i=1;i<=2*q;i++)
	{
		cin>>t[i]>>e[i];
		x+=t[i+1]-t[i];
		y+=e[i+1]-e[i];
	}
	cout<<x<<y;
}
