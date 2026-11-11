#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=2e5+25;
const ll MAXN=1e7+7;
ll n,L,ans=0,cnt=0;
ll o[N],wei[N];
char str[N];
void bao(){
	string st;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=o[i];j++)	st+=str[i];
	}
	ll t=st.length(),mid=(t&1)?(t/2+1):(t/2);
	for(ll i=0;i<mid;i++){
		if(st[i]!=st[st.length()-1-i])	cnt++;
	}
	cout<<cnt<<'\n';
}
void zheng(){
	ll mid=(L&1)?(L/2+1):(L/2),mid_xu=lower_bound(wei+1,wei+1+n,mid)-wei;
	ll i=mid-1,j=mid+1;
	while(i>=1&&j<=L){
		ll i_xu=lower_bound(wei+1,wei+1+n,i)-wei,j_xu=lower_bound(wei+1,wei+1+n,j)-wei;
		ll i_leng=(i_xu==mid_xu)?(i-wei[i_xu-1]):(wei[i_xu]-wei[i_xu-1]);
		ll j_leng=(j_xu==mid_xu)?(wei[j_xu+1]-mid):(wei[j_xu]-wei[j_xu-1]);
		if(str[i_xu]!=str[j_xu]){
			ll t=min(i_leng,j_leng);
			ans+=t;
			if(t==i_leng){
				i=(i-i_leng==0)?1:(i-i_leng);
				j+=t;
			}
			else{
				j+=j_leng;
				i=(i-t==0)?1:(i-t);
			}
		}
		else{
			i=(i-i_leng==0)?1:(i-i_leng);
			j+=j_leng;
		}
	}
	cout<<ans<<'\n';
}
void solve(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>o[i]>>str[i];
		wei[i]=o[i];
		wei[i]+=wei[i-1];
	}
	L=wei[n];
	if(L<=MAXN)	bao();
	else	zheng();
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
	solve();
	return 0;
}
