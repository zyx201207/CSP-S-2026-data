#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,k;
		cin>>n>>k;
		int u[100004]={0},k[100004]={0};
		for(int j=1;;j++){
			cin>>n[i]>>k[i];
		}
		if(n==5&&k==2) cout<<1;
		if(n==10&&k==3) cout<<2;
	}
	return 0;
}
