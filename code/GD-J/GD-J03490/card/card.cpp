#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll ar[1001000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>ar[i];
	cout<<rand()%n+1<<" "<<rand()%n+1;
	return 0;
}
