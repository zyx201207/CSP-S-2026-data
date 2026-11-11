#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 200010;

int n,a[MAXN];
char c[MAXN];

signed main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	
	int prog=0;
	int ans=0;
	int rit=n,rk=a[n];
	for(int fit=1;fit<=n&&fit<rit;fit++){
		int lk=a[fit];
		if(lk<=rk){
			prog+=lk;
			if(c[fit]!=c[rit])ans+=lk;
			rk-=lk;
		}else{
			while(lk>rk&&fit<rit){
				prog+=rk;
				if(c[fit]!=c[rit])ans+=rk;
				lk-=rk;
				rit--;
				rk=a[rit];
			}
			prog+=lk;
			if(c[fit]!=c[rit])ans+=lk;
			rk-=lk;
		}
	}
	cout<<ans;
}

