#include<bits/stdc++.h>
#define dis(ab,cd) ((a[cd]-a[ab])<=d) 
using namespace std;
typedef long long ll;
const int N = 2e6+5;
ll a[N],l[N],r[N],step[N],c,n,d,ans;
bool check(int ll,int rr){
	int cnt=0,w=0;
	for(int k=ll;k<rr;){
		if(k==r[k])return 0;
		step[++cnt]=k,k=r[k];
	}
	step[++cnt]=rr;
	for(int i=2;i<cnt;i++){
		if(step[i]-2>step[i-1]){
			if(dis(step[i]-1,step[i+1])){
				if(w)return 0;
				w++;
			}
			if(dis(step[i]-2,step[i+1]))return 0;
		}
		else if(step[i]-2==step[i-1]){
			if(dis(step[i]-1,step[i+1])){
				if(w)return 0;
				w++;
			}
		}
	}
	return w==1;
}
void sp_A(){
	ll ch=a[2]-a[1],sum=d/ch;
//	cout<<" "<<d<<' '<<a[2]-a[1]<<" "<<d/ch<<" ";
	if(sum<=1){
		cout<<"0\n";
		return;
	}
	cout<<max(n-(2*sum-1),0ll)<<'\n';
}
void sp_B(){
	for(int i=1;i<=n;i++){
		l[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
		r[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		int lx,rx;
		lx=lower_bound(l+1,l+1+n,r[i]-1)-l;
		rx=upper_bound(l+1,l+1+n,r[i]-1)-l;
		if(r[i]-1==i)continue;
		ans+=rx-lx;
	}
	cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c<=6){
			for(int i=1;i<=n;i++){
				l[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
				r[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(check(i,j))ans++;
				}
			}
			cout<<ans<<'\n';	
		}
		if(c==11||c==12)sp_A();
		if(c==13||c==14)sp_B();
	}
	return 0;
}
/*
13 1
5 13
1 3 7 15 20
*/
