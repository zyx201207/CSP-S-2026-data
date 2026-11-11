#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int v[2000006];
void s(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	int cc=v[2]-v[1],k=d/cc;
	if(n==1){
		cout<<0<<"\n";
		return;
	}
	
	if(k<=1||k>=3){
		cout<<0<<"\n";
	}
	else{
		cout<<n-3<<"\n";
	}
}
int main(){
		freopen("subway","r",stdin);
		freopen("subway","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		s();
	}
}

