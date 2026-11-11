#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,d,a[2000005],o,minn=LLONG_MAX;
bool r[100005];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t; 
	while(t--){
		memset(r,0,sizeof(r));
		cin>>n>>d;
		o=0;
		for(int i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
			r[u]++;
			r[v]++;
		}
		bool k=0;
		for(int i=1;i<=n;i++){
			if(r[i]!=r[i-1]){
				if(abs(r[i]-r[i-1])<=d){
					continue;
				}else{
					k=1;
					break;
				}
			}
		}
		if(k) cout<<1;
		else cout<<d-1;
		cout<<"\n";
	}
	return 0;
} 
