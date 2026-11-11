#include<bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE 1
#define duoce 0
typedef long long ll;
const int N=5e5+5;
inline ll read(){
	ll ret=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
void write(ll x){
	if(x<0){
		putchar('-'),x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void solve();
int main(){
	if(ONLINE_JUDGE){
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
	}
	else{
		freopen("xxx.in","r",stdin);
		freopen("ans.out","w",stdout);
	}
	int t=1;
	if(duoce)t=read();
	while(t--)solve();
}
ll n,m;
ll a[N];
ll pre[N];
void solve(){
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll y=m+pre[i];
		//cout<<i<<":"<<y<<endl;
		ll l=1,r=i,p=1;
		while(l<=r){
			//cout<<l<<" "<<r<<endl;
			ll mid=l+(r-l)/2;
			if(a[i]*mid+pre[i-mid]<=y){
				l=mid+1;
				p=mid;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,p);
	}
	write(ans);
}
/*
fc D:\ÏÂÎç\crystal\ans.out D:\ÏÂÎç\crystal\try.out
*/
