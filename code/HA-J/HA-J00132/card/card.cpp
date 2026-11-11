#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	long long maxn;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		maxn=max(maxn,x);
	}
	while(m--){
		cout<<maxn<<" ";
	}
	
}
