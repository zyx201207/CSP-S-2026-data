#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int e[N];
int n;
char z[N];
int ans;
void s1()
{
	string zf=" ";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=e[i];j++)
		{
			zf+=z[i];
		}
	}
	//cout<<zf<<endl;
	int l=1,r=zf.size()-1;
	for(int i=1;l<r;i++)
	{
		
		if(zf[l]!=zf[r])
		{
			//cout<<l<<' '<<r<<endl;
			ans++;
			zf[r]=zf[l];
		}
		l++;
		r--;
		
	}
	cout<<ans<<endl;
	//cout<<zf;
}
void s2()
{
	
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int mx=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>e[i];
		cin>>z[i];
		mx=max(mx,e[i]);
	}
	s1();
	
	
	return 0;
 } 
