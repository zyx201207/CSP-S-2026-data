#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;


int ans=0,sum=0;
int a,b,c,d,e,f;
int Eric;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ans>>sum;
	cin>>a>>b>>c>>d>>e>>f;
	if(ans==sum)
	cout<<'1';
	if(ans!=sum)
	cout<<'0';
	if(a==b)
	cout<<'1';
	if(a!=b)
	cout<<'0';
	if(c==d)
	cout<<'1';
	if(c!=d)
	cout<<'0';
	if(e==f)
	cout<<'1';
	if(e!=f)
	cout<<'0';
	cout<<Eric;
	return 0;
}
