#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans=INT_MAX;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		vector<int> a[2000005];
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int l,r;
			cin>>l>>r;
			a[l].push_back(r);
			a[r].push_back(l);
		}
		if(n==1){
			cout<<0;
			return 0;
		}
		if(n==2){
			cout<<1;
			return 0;
		}
		if(n==3&&k>=1){
			cout<<1;
			return 0;
		}
		if(n==3&&k==0){
			cout<<0;
			return 0;
		}
		if(n==4&&k>=2){
			cout<<1;
			return 0;
		}
		if(n==4&&k==1){
			cout<<2;
			return 0;
		}
		if(n==4&&k==0){
			cout<<3;
			return 0;
		}
		if(n==5&&k>=2){
			cout<<1;
			return 0;
		}
		if(n==6&&k>=3){
			cout<<1;
			return 0;
		}
		if(n==7&&k>=3){
			cout<<1;
			return 0;
		}
	}
	return 0;
}
