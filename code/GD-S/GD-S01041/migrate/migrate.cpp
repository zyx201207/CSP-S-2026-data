#include<bits/stdc++.h>
using namespace std;
int a[5000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,ans = 0;
		cin>>n>>d;
		bool a=1,b=0;
		for(int i =1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>=3){
				a = 0;
			}
			if(i==n%2||i==n%2-1||i==n%2+1){
				if(a[i]-a[1]==0){
					b = 1;
				}
			} 
		}
		if(a){
			int k = 0;
			for(int i =1;i<=n;i++){
				if(a[1]+d<=a[i]&&a[1]+d>=a[i-1]){
					k = i;
				}
			}
			for(int i = 2;i<=k;k++){
				ans+=n-i;
			}
			cout<<ans;
		}
		else{
			cout<<0<<endl;
		}
	}
	
	return 0;
} 
