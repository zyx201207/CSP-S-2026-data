#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	//ifstream cin;
	//ofstream cout;
	//cin.open("travel.in");
	//cout.open("travel.out");
	int n,m;
	cin>>n>>m;
	int a[n],b[n]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		
	}sort(b,b+n);
	cout<<b[m-1];
	return 0;
 } 
