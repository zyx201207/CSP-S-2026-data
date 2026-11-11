#include <bits/stdc++.h>

using namespace std;
const int N=5e5+10;
typedef long long ll;
ll n,m,a[N],ma,shu,sum,id,cnt,b[N],ans=1;
map <ll,int> mp;
bool check(int x){
	for(int i=x;i<=n;i++){
		if(a[i]-a[i-x+1]<=m) return true;
	}
	return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(register int i=1;i<=n;i++){
		scanf("%lld",&b[i]);
		mp[b[i]]++;
	} 
	sort(b+1,b+1+n);
	bool A=1,B=1;
	for(int i=1;i<=n;i++) if(b[i]!=i){
		A=0;
		break;
	}
	ll cha=a[2]-a[1];
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]!=cha) B=0;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
		ll cnt=0,linm=m;
		for(int j=i-1;j>0;j--){
			if(b[i]==b[j]) continue;
			if(linm-(b[i]-b[j])>=0){
				linm-=b[i]-b[j];
				cnt++;
			}else break;
		}
		cnt+=mp[b[i]];
		ans=max(ans,cnt);
	}
	}else if(A){
		for(int i=1;i<n;i++){
			if(m<i) break;
			m-=i;
			ans++;
		}
	}else if(B){
		for(int i=1;i<n;i++){
			if(m<i*cha) break;
			ans++;
			m-=i*cha;
		}
	}else{
		for(int i=1;i<n;i++){
			a[i+1]=a[i]+(b[i+1]-b[i]);
		}
		int l=1,r=1e7;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid)){
				ans=mid;
				l=mid+1;
			}else r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
