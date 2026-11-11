#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,f,xx;
ll n,d;
ll a[10010];
ll b[10010];
ll dx[10010];
map<ll,ll>x;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ll cnt=0;
        f=0,xx=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
		for(int i=1;i<=n;i++){
			xx=b[i]-b[i-1];
		}
		for(int i=1;i<=n;i++){
			if(b[i]-b[i-1]!=xx){
				f=1;
			}
		}
		if(f==0){
			cout<<(n-1)/2;
		}else{		
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(b[j]-b[i]<=d){
						x[b[j]-b[i]]++;
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(x[i]==2){
					cnt++;
				}
			}
			cout<<cnt<<endl;
		}
    }
	return 0;
}
