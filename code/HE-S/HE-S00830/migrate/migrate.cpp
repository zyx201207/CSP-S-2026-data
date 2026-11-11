#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d,a[2000006],f[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ll cnt=0; 
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==1){
			for(int i=1;i<=n;i++){
				ll j=i;
				while((j-=t)>0) f[i]+=f[i-t];
				if(f[i]==2) cnt++;
			}
			cout<<cnt<<"\n";
		}else if(c==11||c==12){
			for(int i=1;i<=n;i++){
				if((a[i]-a[1])%d!=0) cnt++;
			}
			cout<<cnt<<"\n";
		}else{
			ll d[10000001];
			ll cnt=n;
			while(n--) cout<<d[cnt--]<<"\n";
		}
	}
	return 0;
}
