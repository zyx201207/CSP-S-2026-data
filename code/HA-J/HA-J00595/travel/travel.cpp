#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,m,t,w;
	vector<bool> ans(4);
	cin>>n>>m>>t>>w;
	if(n==t){
		cout<<1;
		ans[0]=1;
	}else{
		cout<<0;
	}
	if(ans[0]&&m[0]==w[0]&&m[1]==w[1]){
		cout<<1;
		ans[1]=1;
	}else{
		cout<<0;
	}
	if(ans[1]&&((m[2]<=67&&w[2]<=67)||(m[2]>=68&&w[2]>=68))){
		cout<<1;
		ans[2]=1;
	}else{
		cout<<0;
	}
	if(ans[2]&&abs(m[2]-w[2])==1) cout<<1;
	else cout<<0;
	
	return 0;
}
