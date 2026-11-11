#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int x;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==1||m==1)
	{
		cout<<"0";
	}
	else{
		cout<<a[n-1];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
 } 
