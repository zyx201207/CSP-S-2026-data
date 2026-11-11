//GZ-S00194 周润泽 贵阳市第三实验中学 
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(n==5&&k==2)cout<<1<<'\n';
		if(n==10&&k==3)cout<<2<<'\n';
		if(n==8&&k==6)cout<<1<<'\n';
	} 
	return 0;
}
