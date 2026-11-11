#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
		}
		if(k==n){
			cout<<0<<"\n";
		}else if(k>=n/2){
			cout<<1<<"\n";
		}else{
			int cnt=2,m=n/2;
			while(1){
				m/=2;
				if(k>=m){
					cout<<cnt<<"\n";
					break;
				}
				cnt++;
			}	
		}
	}
	return 0;
}
