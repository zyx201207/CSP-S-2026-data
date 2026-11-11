#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll c,t,n,d,x[N],q[N],lst[N],p[N];
struct Node{
	ll t[N];
	void clear(ll u){
		for(ll i=1;i<=u;i++){
			t[i]=0;
		}
	}
	ll lowbit(ll u){
	    return u&(-u);
    }
    void update(ll u,ll x){
		for(ll i=u;i<=n;i+=lowbit(i)){
			t[i]+=x;
		}
	}
	ll query(ll u){
		ll ans=0;
		for(ll i=u;i>=1;i-=lowbit(i)){
			ans+=t[i];
		}
		return ans; 
	}
};
Node t1,t2;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
while(t--){
	cin>>n>>d;
	t1.clear(n);
	t2.clear(n);
	ll cnt1=0,cnt=0,ans=0;
	for(ll i=1;i<=n;i++){
		lst[i]=0;
		p[i]=0;
		cin>>x[i];
	}
	q[1]=0;
	for(ll i=2;i<=n;i++){
		cnt+=x[i]-x[i-1];
		cnt1++;
		while(cnt>d){
			cnt-=x[i-cnt1+1]-x[i-cnt1];
			cnt1--; 
		}
		q[i]=cnt1;
	}
	if((11<=c)&&(c<=12)){
		if((q[n]*2)>n||q[n]<2){
			cout<<"0\n";
		}else{
			cout<<n-q[n]*2+1<<"\n";
		}
		continue;
	}
	for(int j=1;j<=n;j++){
		t1.clear(n);
	    t2.clear(n);
	    for(int i=0;i<=n;i++){
	    	p[i]=0;
	    	lst[i]=0;
		}
		for(int i=j;i<=n;i++){
			int l=i-q[i];
			l=max(j,l);
			if((i==j)){
				p[i]=1;
		        lst[p[i]]=i;
		        t1.update(i,1);
		        continue;
			}else if(q[i]==0){
				break;
			}
			int r=lst[p[l]];
			int u=t1.query(r)-t1.query(l-1),v=t2.query(r)-t2.query(l-1);
			p[i]=p[l]+1;
			lst[p[i]]=i;
			if((v==0)){
				if(u==2){
					ans++;t1.update(i,u);
				}else if(u<2){
					t1.update(i,u);
				}else{
					t2.update(i,1);
				}
			}else{
				t2.update(i,1);
			}
		}
    } 
    cout<<ans<<"\n";
}
}
