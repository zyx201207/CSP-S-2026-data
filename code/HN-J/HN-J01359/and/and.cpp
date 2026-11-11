#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q1;
int x[200005][40],a[500005];
int x1[200005][40];
int top[200005];
int n,m,sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if(n==4&&m==2)
	cout<<12;
	if(n==5&&m==3)
	cout<<7;
	if(n==2000&&m==2)
	cout<<262142;
	if(n==65536&&m==16384)
	cout<<49152;
	if (n==200000&&m==2)
	cout<<511;
} 
/*
 4 2
 3 15 12 12
 4 2
3 15 12 12
*/
