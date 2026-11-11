#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			cout<<i;
		}
	}
	return 0;
}
