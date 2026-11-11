#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,sj[500000+50];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>sj[i];
	
	ll tmp=sj[0];
	bool same=true;
	for(ll i=1;i<n;i++){
		if(sj[i]!=tmp){
			same=false;
			break;
		}
	}
	if(same) cout<<m;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
