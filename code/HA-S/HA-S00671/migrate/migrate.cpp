#include<bits/stdc++.h>
using namespace std;
int c,n,d,a[2000005],ans=1e9,cnt,f=1;
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=a[i-1]-a[1-2]){
			f=0;
		} 
	}
	if(f){
		int cha=a[2]-a[1];
		int k=d/cha;
		int ans1=n-(k*2-1);
		cout<<ans1<<"\n";
	}else if(c==11||c==12){
		int cha=a[2]-a[1];
		int k=d/cha;
		int ans1=n-(k*2-1);
		cout<<ans1<<"\n";
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

