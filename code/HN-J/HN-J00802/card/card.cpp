#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[11111];
	for(int i=0;i<=n;i++)
	{
		cin>>a[i]; 
	}
	cout<<n<<m<<a[1];
	return 0;
}
