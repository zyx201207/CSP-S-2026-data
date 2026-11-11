#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int n,m;
int a[M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[n]<<1<<n<<endl;
	return 0;
}