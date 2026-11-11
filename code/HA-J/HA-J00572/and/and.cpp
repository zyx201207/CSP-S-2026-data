#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
freopen,"and.in" "r",stdin;
freopen,"and.out" "w" ,stdout;
int n,m,p;
cin>>n>>m;
cin>>p;
for(int i=1;i<=n-1;i++)
{
int t;
cin>>t;
if(t>p)
{
swap(t,p);	
	}	
	}
	cout<<p;	
return 0;	
}
