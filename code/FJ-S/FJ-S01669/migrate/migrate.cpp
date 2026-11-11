#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c=read(),t=read(),x[2000010],b[2000010];
	while(t--){
		ll n=read(),d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		if(x[n]-x[1]<=2*d){
			if(x[n]-x[1]<=d) cout<<"0\n";
			else{
				int ans=0;
				for(int i=4;i<=n;i++){
					if(x[i]-x[i-2]<=d&&x[i]-x[i-3]<2*d&&x[i]-x[i-3]>d&&x[i-3]-x[i-1]<=d) ans++;
				}
				cout<<ans<<"\n";
			}
		}
		else{
			cout<<n<<"\n";
		}
	}
	return 0;
}
