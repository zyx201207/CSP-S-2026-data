#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long ans,w[5000010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		ans+=w[i];
	}
	cout<<ans;
}
