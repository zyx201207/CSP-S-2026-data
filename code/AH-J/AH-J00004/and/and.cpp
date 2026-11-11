#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,cnt;
ll t[200005];
string p[200005];
bool f[200005];
ll a[200005];
ll maxn;
string zh(ll x){
	string k="";
	while(x){
		k=char('0'+x%2)+k;
		x/=2;
	}
	return k;
}
ll pd(){
	ll ans=0;
	ll sum=n;
	for(ll j=0;j<maxn;j++){
			for(ll i=1;i<=n;i++){
				if(f[i]==0){
					t[j]+=p[i][j]-'0';
				}
			}
			for(ll i=1;i<=n;i++){
				if(f[i]==0){
					if(p[i][j]=='1'&&t[j]>=m&&sum>m){
						f[i]=0;
					}else if(t[j]>=m&&sum>m){
						f[i]=1;
						sum--;
					}
				}
			}
			if(t[j]>=m) ans+=pow(2,maxn-j-1);
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		string t=zh(a[i]);
		p[++cnt]=t;
		maxn=max(maxn,(ll)t.size());
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=cnt;i++){
		if((ll)p[i].size()<maxn){
			while((ll)p[i].size()<maxn){
				p[i]="0"+p[i];
			}
		}
		cout<<p[i]<<endl;
	}
	cout<<pd();
	return 0;
}
