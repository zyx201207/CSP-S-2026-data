#include <bits/stdc++.h>
using namespace std;
int n,m;
string pd,pz,b;
bool pdf[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b;
		pd+=b;
	}
	for(int i=1;i<=m;i++){
		cout<<i<<" ";
	}
	
	return 0;
}
