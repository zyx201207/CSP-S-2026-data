#include<iostream>
#include<bits/stdc++.h>
using namespace std;
# define r return
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int num[n+1];
	for(int i=1;i<=n;i++)
		cin>>num[i];
	for(int i=1;i<=n;i++)
		cout<<num[i];
	return 0;
}

