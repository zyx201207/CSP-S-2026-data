#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
const ll INF=1e18;
ll a[N];
ll ans=1;
ll n,m;
bool cmp(ll x,ll y){
	return x<y;
}

void cz(ll d){
		ll mid;
		for(int i=1;i<n;i++){
			 ll xx=a[i];ll sum=1;
			for(int j=i+1;j<=n;j++){
				if(xx==a[j])sum++;
			}
			if(sum>ans)mid=xx;
		}
		ll aa;
		for(int i=1;i<=n;i++)
			if(a[i]==mid){
			aa=i;
			break;
		}
		if(ans==1){
			if(n%2==0)aa=n>>1;
			else aa=(n>>1)+1;
		}
		mid=a[aa];
		for(int i=aa+1,j=aa-1,z=1;z<=n;z++,i++,j--){
			ll s=INF;
			if(d<=0)break;
			if(j>0&&i<=n){
				if(a[i]==mid)ans++;
				if(a[j]==mid)ans++;
				if(mid+d>=a[i])s=min(s,a[i]-mid);
				if(a[j]+d>=mid)s=min(s,mid-a[j]);
				if(s<=d)ans++,d-=s;
			}else if(j<=0&&i<=n){
				if(a[i]==mid)ans++;
				if(mid+d>=a[i])ans++,d-=a[i]-mid;
			}else if(i>n&&j>0){
				if(a[j]==mid)ans++;
				if(a[j]+d>=mid)ans++,d-=mid-a[j];
			}else break;
		}
	
	cout<<ans<<"\n";
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(n==1){	
		cout<<ans<<"\n";
		return 0;
	}
	else if(n==2){
		ans+=(m+min(a[1],a[2])>=max(a[1],a[2]))?(1):(0);
		cout<<ans<<"\n";
		return 0;
	}
	else if(m==0){
		for(int i=1;i<=n;i++){
			 ll xx=a[i];ll sum=1;
			for(int j=i+1;j<=n;j++){
				if(xx==a[j])sum++;
			}
			ans=max(ans,sum);	
		}
		cout<<ans<<"\n";
		return 0;
	}
	cz(m);
	return 0;
}
