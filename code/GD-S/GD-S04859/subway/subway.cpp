#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,N=1e5+6;

int main(){
     freopen("subway.in","r",stdin);
     freopen("subway.out","w",stdout);
     ios::sync_with_stdio(false);
     cin.tie(nullptr),cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    vector<long long> w(m);
    for(int i=1;i<=m;i++)
    {
    	cin>>w[i];
	}
	long long k;
	vector<vector<long long>> a(N,vector<long long> (N,0));
	vector<vector<long long>> b(N,vector<long long> (N,0));
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<k;j++)
		{
			cin>>a[i][j]>>b[i][j];
		}
	}
	long long start,last;
	for(int i=1;i<=q;i++)
	{
		cin>>start>>last;
		long long ans;
		ans+=w[start]+w[last];
		for(int i=1;i<=n;i++)
	   {
		
		for(int j=1;j<k;j++)
		{
			if(a[i][j]==strat)
			{
				ans+=b[i][j];
				start=a[i][j+1];
			}
		}
	   
	}
	
	
	  return 0;
 } 
