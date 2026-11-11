#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans=0;
ll gs[200005];
char zf[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>gs[i];
		cin>>zf[i];
	}
	int i=1,j=n;
	ll ti=gs[1],tj=gs[n];
	while(i<j){
		if(ti>tj){
			if(zf[i]!=zf[j]) ans+=tj;
			ti-=tj;
			j--;
			tj=gs[j];
		}
		if(tj>ti){
			if(zf[i]!=zf[j]) ans+=ti;
			tj-=ti;
			i++;
			ti=gs[i];
		}
		if(ti==tj){
			if(zf[i]!=zf[j]) ans+=ti;
			i++;
			j--;
			ti=gs[i];
			tj=gs[j];
		}
	}
	cout<<ans;
	
	
	return 0;
}
