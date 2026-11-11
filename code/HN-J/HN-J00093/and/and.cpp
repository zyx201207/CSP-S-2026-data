#include<bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("C:/Users/Administrator/Desktop/and/and2.in","r",stdin);
//	freopen("C:/Users/Administrator/Desktop/.txt","w",stdout);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,o,maxn;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>o;
		maxn=max(maxn,o);
	}
	cout<<maxn;
	return 0;
}

