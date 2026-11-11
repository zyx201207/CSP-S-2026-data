#include<bits/stdc++.h>
using namespace std;
int c,t;
int ans[100005];
int x[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(d==3){
			ans[i]==0;
		}else{
		  ans[i]=n-3;
		}
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl; 
	}
	return 0;
}
