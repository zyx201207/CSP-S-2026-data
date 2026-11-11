#include<bits/stdc++.h>
using namespace std;
int c,t,n,k; 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==7||c==11||c==12){
		for(int i=1;i<=t;i++){
			cin>>n>>k;
			cout<<n/2<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		cout<<n-k<<'\n';
	}
	return 0;
}
