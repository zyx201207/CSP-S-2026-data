#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
    int s=a[1]-a[0];
    s=abs(s);
    int s1=s;
    while(m>0)
    {
    	m-=s;
    	s+=s1;
    	ans++;
    	if(ans==n) break;
	}
	cout<<ans;
	return 0;
} 
