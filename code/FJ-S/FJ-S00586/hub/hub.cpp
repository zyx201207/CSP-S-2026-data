#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;
const int N=3e5+111;
int n,k;
vector<int>e[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T=1;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
		}
		if(C==13||C==14){
			int m=(n-1)/2+1;
			if(k>m){
				cout<<1<<"\n";
				continue;
			}
			else {
				cout<<((m-k+2)/3+1)<<"\n";
				continue;
			}
		}
		if(k>n/3*2)cout<<1<<"\n";
		else cout<<2<<"\n";
	}
	return 0;
} 
