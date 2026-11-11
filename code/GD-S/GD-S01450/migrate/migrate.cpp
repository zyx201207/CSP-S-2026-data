#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int n,d;
int x[N];
int zd=INT_MAX;
int i;
int ans;
int f;
int main(){
	freopen("migrate1.in","r",stdin);
	freopen("migrate1.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=2;i<=n;i++){
			if(i%(d+1)==1 ) ans++;
		}
		if(d!=1) cout<<ans<<'\n';
		else cout<<0;
	}
}
