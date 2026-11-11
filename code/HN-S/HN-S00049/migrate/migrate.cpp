#include<bits/stdc++.h>
using namespace std;
		long long a[2000050];
		int n,d;
int f(int x,int i){
	for(;i<=n;i++) if(a[i]==x) return i;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++){
			bool b=0;
			int s=d*2-1;
			int t=f(a[i]+s,i);
			if(!t) continue;
			if(f(a[i]+d,i)&&f(a[i]+d-1,i)) b=1;
			
			if(b) ans++;
		}
		cout<<ans<<endl;
	} 
	return 0;
}
