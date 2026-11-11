#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	ios::sync_with_stdio(),cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){ 
		int n,k;
		cin>>n>>k;
		int a[n+1];
		while(--n){
			int s;
			cin>>s;
			cin>>a[s];	
		}
		cout<<k-1<<"\n";
	}



	return 0;
}



