#include<iostream>
using namespace std;
int c,t,n,k;
void sol(){
	cin>>n>>k;
	int tmp=(n-(k-1)*(n/k-1)-k)>>1;
	if((n/k-1)&1){
		tmp=min(tmp,(n/k-1)/2+1);
	}
	else{
		tmp=min(tmp,(n/k-1)/2);
	}
	cout<<tmp<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		sol();
	}
	return 0;
}
