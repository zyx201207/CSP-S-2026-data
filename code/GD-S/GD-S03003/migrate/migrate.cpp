#include<bits/stdc++.h> 
using namespace std;
int nm[2000010];
int d,n;
int f(int i){
	if(i<=0){
		return f(i+1)+f(i+2);
	}
	if(i==1){
		return 1;
	}
	if(i<=d){
		return 1;
	}
	return f(i-1)+f(i-d);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.ont","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>nm[i];
		}
		for(int i=1;i<=n;i++){
			if(f(nm[i])==2){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
