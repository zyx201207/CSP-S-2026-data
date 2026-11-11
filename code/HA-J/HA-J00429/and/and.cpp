/*永远铭记------丁浩文------史诗级大帅哥*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define dd double
#define pii pair<ll,ll>
#define pll pair<ll,ll>
ll read(){
	char ch=getchar();
	ll f=1;
	ll x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const ll N=2e5+999;
ll n,m;
bool a[N][32];
//io
void input(){
	n=read(),m=read();
	for(ll i=1;i<=n;i++){
		ll x=read();
		ll now=1;
		for(ll cnt=0;cnt<=30;cnt++){
			a[i][cnt]=x&now;
			now<<=1;
		}
	}
}
//solve
bool ans[32]; 
void solve(){
	vector<ll>cho;
	for(ll i=1;i<=n;i++)cho.push_back(i);
	for(ll cnt=30;cnt>=0;cnt--){
		vector<ll>now;
		for(ll i=0;i<cho.size();i++){
			if(a[cho[i]][cnt])now.push_back(cho[i]);
		} 
		if(now.size()>=m){
			cho=now;
			ans[cnt]=1;
		}else{
			ans[cnt]=0;
		}
	} 
	ll res=0;
	for(ll i=0,now=1;i<=30;i++){
		if(ans[i])res+=now;
		now<<=1;
	}
	cout<<res;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);


	input();
	solve();
	return 0;
}
/*

4 2
3 15 12 12

*/
