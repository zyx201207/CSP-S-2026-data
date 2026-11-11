#include<bits/stdc++.h>
using namespace std;
long long c,T,n,a[2000010],cha,m;
void solve(){
    cin>>n>>m;
    long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
	if(n==1){
        cout<<0<<"\n";
        return;
    }
    cha=a[2]-a[1];
    cha=m/cha;
    if(cha==0){
    	cout<<0<<"\n";
    	return;
	}
    for(int i=2;i<n;i++){
        if((i%cha)!=0){
            ans+=(n+1)-(i+1);
    	}
    }
    cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>c>>T;
    while(T--){
        solve();
    }
	return 0;
}


