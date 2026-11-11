#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,ans;
ll m,g[N],s[N];
ll minx=1e12;
inline ll minn(const ll &a,const ll &b){
	return a>=b?b:a;
}
bool check(int u){
	ll cnt=LONG_LONG_MAX;
	for(int i=1;i<=n-u+1;i++){
		int j=i+u-1;
		cnt=minn(cnt,s[i-1]+u*g[j]-s[j]);
	}
	if(cnt<=m) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	for(int i=1;i<=n;i++){
		g[i]+=minx;
	}
	sort(g+1,g+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+g[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1; 
		}
	}
	cout<<ans<<endl;
	return 0;
} 


