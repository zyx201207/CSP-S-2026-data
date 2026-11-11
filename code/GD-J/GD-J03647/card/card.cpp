#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500009],t[500009],f[500009],ans[500009];
bool b=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool v[m+1]={0};
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
		if(i!=1&&a[i]<a[i-1]) b=0;
	}
	if(b&&n*n>2e8){
		f[0]=0;
		for(ll i=1;i<=m;i++){
			f[i]=f[i-1]+t[i];
		}
		for(ll i=1;i<=m;i++) cout<<f[i]<<' ';
		return 0;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2&&n*n>2e8){
		ll x=0,y=0;
		for(ll i=1;i<=n;i++){
			if(a[i]==a[n]&&a[i]==1) x++;
			else if(a[i]==a[n]) y++;
			else if(a[i]!=a[n]) x++,y++;
		}
		cout<<x<<' '<<y;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		memset(v,0,sizeof v);
		stack<ll> st;
		for(ll j=i;j<=n;j++){
			if(!v[a[j]]){
				st.push(a[j]);
				v[a[j]]=1;
			}
			else{
				while(st.size()&&st.top()!=a[j]){
					v[st.top()]=0;
					st.pop();
				}
			}
		}
		while(st.size()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<' ';
	fclose(stdin);
	fclose(stdout);
} 
