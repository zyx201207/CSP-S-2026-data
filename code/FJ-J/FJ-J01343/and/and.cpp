#include<bits/stdc++.h>
using namespace std;

int n,m;
long long ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			if(k>ans) ans=k;
		}
		cout<<ans;
		return 0;
	} 
	return 0;
}

//本题不会做，故留此纪念TT;;;;rp++;;;; 
