#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	ll x=1,y=n;
	ll ans=0;
	while(x<y){
		if(b[x]==b[y]){
			ll minn=min(a[x],a[y]);
			a[x]-=minn;
			a[y]-=minn;
			if(a[x]==0)x++;
			if(a[y]==0)y--;
		}else{
			ll minn=min(a[x],a[y]); 
			ans+=minn;
			a[x]-=minn;
			a[y]-=minn;
			if(a[x]==0)x++;
			if(a[y]==0)y--;
		}
		
	}
	cout<<ans;
	
	return 0;
}
