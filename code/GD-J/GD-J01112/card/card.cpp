#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],b[200010],c[10],d[3];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++; 
	}
	if(m==1){
		cout<<(n+1)/2;
		return;
	}
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=b[i];
		cout<<cnt<<' ';
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) solve();
	return 0;
}
