#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int MAXN=5e5+5; 
ll zong,n,m,a[MAXN],b[MAXN],ans,cnt,sum,minn=INT_MAX,maxn=INT_MIN,cut[MAXN];
double temp;
bool special=1;
void displace(ll k){
	for(int i=1;i<=n;i++) b[i]=abs(a[i]-k);
}
void slove(){
	ll mid=zong/n,dxd=0;
	ans=1;
	for(int i=1;i<n;i++){
		dxd+=i;
		if(dxd>m) break;
		ans++;
		dxd+=i;
		if(dxd>m) break;
		ans++;
	}
	if(dxd>m){
		cout<<ans;
		return ;
	}else{
		cout<<n;
		return ;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zong+=a[i];
		if(a[i]!=i) special=0;
		cut[a[i]]++;
		minn=min(a[i],minn),maxn=max(maxn,a[i]);
	}
	if(special){
		slove();
		return 0;
	}
	if(m==0){
		for(int i=1;i<=n;i++){
			if(cut[a[i]]>1) ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int k=minn;k<=maxn;k++){
		displace(k);
		cnt=0,sum=0;
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++){
			sum+=b[i];
			if(sum>m) break;
			cnt++;
		}
		ans=max(cnt,ans);
		if(ans==n) break;
	}
	cout<<ans;
	return 0;
}
