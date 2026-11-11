#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		if(k==n){
			cout<<0<<endl;
			t--;
			continue;
		}
			if(k==1){
				cout<<n/4+1<<endl;
				t--;
				continue;
			}
			int lenth=n-n/2+1;
			lenth-=k;
			cout<<(lenth+3)/4<<endl;
		t--;
	}
	return 0;
} 
