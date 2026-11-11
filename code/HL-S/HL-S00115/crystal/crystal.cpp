#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,cr[500010],p[500010];
bool chec(int mag){
	for(int i=mag;i<=n;i++){
		int needin=cr[i]*mag-p[i]+p[i-mag];
		if(needin<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&cr[i]);
	}
	sort(cr+1,cr+n+1);
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]+cr[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(r-l)/2+l;
		if(chec(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
}
//oh what a t1!
//much more easier than csp-s2025 t1
//15:14:34   Takatori
