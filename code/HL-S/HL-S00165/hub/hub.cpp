#include <bits/stdc++.h> 

using namespace std;

struct z{
	int u;
	int v;
}a[1001];

int main(){

	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	int c,t;
	cin >>c>>t;
	
	int n,k;
	while(t--){
		cin >>n>>k;
		for (int i=1;i<=n-1;i++){
			cin >>a[i].u>>a[i].v;
		}
	}
	
	
	
	return 0;
};

