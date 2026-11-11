#include<bits/stdc++.h>
using namespace std;
long long c,t,d,n,a[2000005];
int main(){
	freopen("migrate3.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-d*2+1;i++){
			long long w1=0,w2=0,w3=0;
			for(int j=i+1;j<i+d*2;j++){
				if(a[j]==a[i]+d) w1=1;
				if(a[j]==a[i]+d-1) w2=1;
				if(a[j]==a[i]+d*2-1) w3=1;
				if(w1==1&&w2==1&&w3==1) break;
			}if(w1==1&&w2==1&&w3==1) ans++;
		}cout<<ans<<"\n";
	}return 0;
} 
