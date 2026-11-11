#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N=1e6+5;
int n,k,c,T;
int fa[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=2;i<=n;i++){
			cin>>fa[i];
		}
		if(n==k){
			cout<<0<<'\n';
		}
		else if(k>=n/2){
			cout<<1<<'\n';
		}
		else{
			cout<<((n/2)-k+3)/4+1<<'\n'; 
		}
	}
	return 0;
}


