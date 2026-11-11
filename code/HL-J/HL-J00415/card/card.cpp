#include <bits/stdc++.h>
using namespace std;
int card[1000010],table[1000010][1000010];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	cout<<n-1<<" "<<m-2<<" "<<n;
	return 0;
}
