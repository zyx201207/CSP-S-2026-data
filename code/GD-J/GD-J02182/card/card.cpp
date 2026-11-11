#include<bits/stdc++.h>
using namespace std;
int m,n,k,a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i <=n;i++){
		cin>>a[i];
	}
	for(int i=1;i <=n;i++){
		cout<<a[i];
	}
	return 0;
}
