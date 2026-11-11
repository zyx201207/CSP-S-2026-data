#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll a[N],p[N][2];
char s[N],q[N][2];
ll id[2];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	ll sum=0;
	for(ll i=1;i<=n;i++){
		ll x;
		cin>>x;
		a[i]=x;
		char c;
		cin>>c;
		s[i]=c;
		sum+=x;
	}
	ll mid=sum/2;
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		cnt+=a[i];
		p[++id[0]][0]=min(mid,cnt);
		q[id[0]][0]=s[i];
		if(cnt>=mid){
			break;
		}
	}
	cnt=0;
	for(ll i=n;i>=1;i--){
		cnt+=a[i];
		p[++id[1]][1]=min(mid,cnt);
		q[id[1]][1]=s[i];
		if(cnt>=mid){
			break;
		}
	}
	ll i=1,j=1;
	ll ans=0;
	while(!((i>id[0])||(j>id[1]))){
		if(p[i][0]>p[j][1]){
			ll t=p[j][1]-max(p[i-1][0],p[j-1][1]);
			if(q[i][0]!=q[j][1]){
				ans+=t;
			}
			j++;
		}
		else if(p[i][0]<p[j][1]){
			ll t=p[i][0]-max(p[i-1][0],p[j-1][1]);
			if(q[i][0]!=q[j][1]){
				ans+=t;
			}
			i++;
		}
		else{
			ll t=min(p[j][1]-p[i-1][0],p[i][0]-p[j-1][1]);
			if(q[i][0]!=q[j][1]){
				ans+=t;
			}
			i++;
			j++;
		}
	}
	cout<<ans;
	return 0;
}
