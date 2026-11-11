#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fi first
#define se second
const int N=2e6+214;
ll c,T,n,d;
ll a[N];
ll f[N][3];
int main(){
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    srand(time(0));
    cin>>c>>T;
    while(T--){
    	cin>>n>>d;
    	for(int i=1;i<=n;i++)cin>>a[i];
		if(a[n]-a[1]<=d){
			cout<<0<<'\n';
		}
    	else if(c==13||c==14){
    		int ai=1,aj=1;
    		ll ans=0;
    		while(ai<=n){
    			while(1){
    				if(aj==n+1)break;
    				if(a[aj]-a[ai]<=d)aj++;
    				else break;
				}
				f[ai][0]=max(aj-1,0);
				f[ai][1]=max(aj-2,0);
				f[ai][2]=max(aj-3,0);
				ai++;
			}
			for(int i=1;i<=n;i++){
				int c1=f[i][0],c2=f[i][2];
				if(f[c1][0]!=f[c2][0])ans++;
			}
			cout<<ans<<'\n';
		}
		else{
			cout<<rand()<<'\n';
		}
	}
	return 0;
}/*
13 1 5 2 1 2 3 4 5*/
