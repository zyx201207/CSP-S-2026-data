#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct wyt{
	ll ct,sy;
}awa[200005];
ll n,m,a[200005],ccc[4],ans,cnt;
bool flag[200005],ff,fb,fla;
ll get2(ll x){
	ll cnt=0;
	while(x>0){
		cnt+=(x%2);
		x/=2;
	}
	return cnt;
}
bool cmp(wyt a,wyt b){
	if(a.sy==b.sy)return a.ct<b.ct;
	return a.sy<b.sy;
}
void dfs(ll now,ll lg){
	if(lg==0){
		for(ll i=1;i<=n;i++){
			if(a[i]>ans)
			flag[i]=1;
			dfs(a[i],1);
			flag[i]=0;
		}
		return ;
	}
	if(lg==m){
		ans=max(ans,now);
		return ;
	}
	for(ll i=1;i<=n;i++){
		if(!flag[i]&&now&a[i]>ans){
			flag[i]=1;
			dfs(now&a[i],lg+1);
			flag[i]=0;
		}
	}
}
bool get2(int x){
	while(x>0){
		if(x%2!=0)return false;
		x/=2;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)fb=1;
		if(!get2(a[i]))ff=1;
		if(a[i]>=4)fla=1;
		if(a[i]<4)ccc[a[i]]++;
	}
	sort(a+1,a+1+n);
	if(n<=20){
//		cout<<1<<'\n';
		dfs(0,0);
		cout<<ans;
		return 0;
	}
	if(m==1){
//		cout<<2<<'\n'; 
		cout<<a[n];
		return 0;
	}
	if(m==2&&n<2000){
//		cout<<3<<'\n';
		for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
		cout<<ans;
		return 0;
	}
	if(m==n){
//		cout<<4<<'\n';
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==n-1){
//		cout<<5<<'\n';
		ll cnt=a[n];
		for(int i=n-1;i>=2;i--)cnt&=a[i];
		cout<<max(cnt,a[1]);
	}
	if(!ff){
//		cout<<6<<'\n';
		cout<<a[n-m+1];
		return 0;
	}
	if(!fla){
//		cout<<7<<'\n';
		if(ccc[3]>=m){
			cout<<"3";
			return 0;
		}
		m-=ccc[3];
		if(ccc[2]>=m){
			cout<<"2";
			return 0; 
		}
		if(ccc[1]>=m){
			cout<<"1";
			return 0;
		}
		cout<<"0";
		return 0;
	}
//	cout<<8<<'\n';
	for(ll i=1;i<=n;i++){
		awa[i].ct=a[i];
		awa[i].sy=get2(awa[i].ct);
	}
	for(ll i=n;i>=(n-m+1);i--){
		if(i==n)cnt=awa[i].ct;
		else cnt&=awa[i].ct;
	}
	sort(awa+1,awa+1+n,cmp);
	for(ll i=n;i>=(n-m+1);i--){
		if(i==n)ans=awa[i].ct;
		else ans&=awa[i].ct;
//		cout<<ans<<" "<<a[i].ct<<'\n';
	}
	cout<<max(ans,cnt);
	return 0;
}
