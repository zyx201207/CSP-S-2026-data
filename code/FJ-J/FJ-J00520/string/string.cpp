#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n;
char c[N];
ll l[N],r[N],a[N],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l[i]=r[i-1]+1LL;
		r[i]=l[i]+a[i]-1LL;
	}
	ll lef=1,rig=r[n],lid=1,rid=n;
	while(lid<rid){
		ll sl=r[lid]-lef+1LL,sr=rig-l[rid]+1LL;
		if(sl<sr){
			if(c[lid]!=c[rid]) ans+=sl;
			lid++;
			lef=l[lid];
			rig-=sl;
		}else if(sl==sr){
			if(c[lid]!=c[rid]) ans+=sl;
			lid++;
			lef=l[lid];
			rid--;
			rig=r[rid];
		}else{
			if(c[lid]!=c[rid]) ans+=sr;
			rid--;
			rig=r[rid];
			lef+=sr;
		}
	}
	cout<<ans;
	return 0;
}
