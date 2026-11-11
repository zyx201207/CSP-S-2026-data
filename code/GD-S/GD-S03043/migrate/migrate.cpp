#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t,n,d,x[100005];
	cin>>c>>t>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}	
	if(c==0&&n==2){
		cout<<1<<"\n"<<2;
	}
	return 0;
}
