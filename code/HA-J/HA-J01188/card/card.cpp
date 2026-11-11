#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cout<<n<<" ";
	}
	return 0;
}
