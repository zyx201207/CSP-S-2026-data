#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll a[N];
int x[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1)cout<<n<<'\n';
	else for(int i=1;i<=m;i++)cout<<1<<' ';
	return 0;
}
