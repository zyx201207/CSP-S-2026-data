#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[2000005];
int ans;
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		int n,d;
		cin>>n>>d;
		for(int i=1;i>=n;i++){
			cin>>x[i];
		} 
		if(d<=1){
			cout<<0<<endl;
			continue;
		}
		
		if((2*(x[2]-x[1]))>d){
			cout<<0<<endl;
			continue;
		}
		int xb=0;
		if((x[n]-x[1])%d==0){
			xb=(x[n]-x[1])/d;
		}else{
			xb=int ((x[n]-x[1])/d);
			xb+=1;
		}
		while(d>=2){
			ans+=(n-d-1);
			d--;
		}
		cout<<ans<<endl;
	} 
	return 0;
}

