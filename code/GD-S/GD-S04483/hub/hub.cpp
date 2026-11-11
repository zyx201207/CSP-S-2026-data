#include<bits/stdc++.h>
using namespace std;
int C,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>C>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
		}
		cout<<(n-1)/2<<'\n';
	}
	return 0;
}

