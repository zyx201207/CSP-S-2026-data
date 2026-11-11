#include<bits/stdc++.h>
using namespace std;
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	vector<int>yuan(n);
	for(int i=1;i<=n;i++){
		cin>>yuan[i];
	}
	for(int i=1;i<=m;i++){
		cout<<n<<" \n"[i==m];
	}
	return 0;
}
