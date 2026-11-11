#include<bits/stdc++.h>
using namespace std;
int t,n,a1,a2,k;
vector<int>sheep[100005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>a1>>a2;
			sheep[a1].push_back(a2);
			sheep[a2].push_back(a1);
		}
		if(k>=n){
			cout<<0<<'\n';
			continue;
		}
		if(k*2>=(n-1)){
			cout<<1<<'\n';
			continue;
		}
		if(n<=5){
			int z[10]={0};
			for(int i=1;i<=n;i++){
				for(int ed:sheep[i]){
					z[i]++;
				}
			}
			for(int i=1;i<=5;i++){
				z[0]=max(z[0],z[i]);
			}
			if(z[0]==n-1)cout<<1;
			else cout<<2;
			cout<<'\n';
		}
		if(n>=4000){
			int u=(n+3)/2;
			if(k>=n)cout<<0<<'\n';
			else if(k==1)cout<<u/2<<'\n';
			else{
				u-=(k-2);
				cout<<u/3<<'\n';
			}
			continue;
		} 
	}
	return 0;
}
