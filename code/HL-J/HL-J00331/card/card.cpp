#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    stack<int> s;
    map<int,int> mp;
    map<int,int> mpp;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			mp[a[j]]++;
		    if(mp[a[j]]>1)
		    {
			    while(s.top()!=a[j])
			    {
			    	int x=s.top();
			    	mp[x]--;
			    	s.pop();
				}
				mp[a[j]]--;
		    } 
		    s.push(a[j]);
		}
	    for(int k=1;k<=m;k++)
	    {
	    	mpp[k]+=mp[k];
	    	mp[k]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<mpp[i]<<" ";
	}
    return 0;
}

