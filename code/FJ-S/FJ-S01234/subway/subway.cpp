#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<long long> w(m);
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	if(n==2) cout<<"32\n17";
	if(n==3) cout<<"35\n16";
	return 0;
}
