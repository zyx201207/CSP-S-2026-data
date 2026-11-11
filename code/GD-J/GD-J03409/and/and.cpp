#include<bits/stdc++.h>
using namespace std;
int n,m,l[20005];
int main()
{
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	cout<<l[n-1];
    return 0;
}
