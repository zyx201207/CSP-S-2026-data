#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	 cin>>c>>t;
	while(t--){
		int n,k,cnt;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<cnt<<'\n';
	}
	return 0;
} 
