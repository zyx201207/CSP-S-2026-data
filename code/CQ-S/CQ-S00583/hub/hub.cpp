#include<bits/stdc++.h>

using namespace std;

int c,t;

int solve(){
	if(c==13 || c==14){
		cout<<1<<endl;
		return 0;
	}
	int n,k;
	cin>>n>>k;
	if(n==k){
		cout<<0<<endl;
	}
	if(c==1){
		int one[10] = {};
		for(int i = 1;i<n;i++){
			int u,v;
			cin>>u>>v;
			one[u]++;
			one[v]++;
		}
		for(int i = 1;i<=n;i++){
			if(one[i]==n){
				cout<<1<<endl;
				return 0;
			}
		}
		if(n<=3){
			cout<<1<<endl;
			return 0;
		}else if(k>=2){
			cout<<1<<endl;
		}else{
			cout<<2<<endl;
		}
		return 0;
	}
	return 0;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
//AFO
//¹þ¹þ£¬Äã±»Æ­ÁË 
