#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,k;
int u,v;
int mini;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		mini=INT_MAX;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			mini=min(mini,abs(u-v));
		}
		cout<<mini<<'\n';
	}
}
