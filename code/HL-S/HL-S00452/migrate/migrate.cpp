#include<bits/stdc++.h>
using namespace std;
#define int long long

void Migrate(){
	int ans=0,x=0,y=0;
	int n,d;
	vector<int> a(n);
	
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i!=0){
			x=x+a[i]-a[i-1];
		}else{
			x=0;
		}
	}
	if(d>=n-1){
		ans=0;
	}else{
		for(int i=0;i<x-d;i++){
			y=(x-d)/i;
			if(y==2){
				ans++;
			}else{
				continue;
			}
			
		}
		
	}
		
	cout<<ans<<endl;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		Migrate();	
	}
	
	return 0;
}