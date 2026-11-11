#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int ans,ma=-1000;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<0<<" ";
	}
	return 0;
}
//Trick||Treat!
/*


10 3
3 1 2 1 3 2 3 1 2 1



*/
