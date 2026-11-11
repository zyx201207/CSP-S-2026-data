#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m;
ll a[N];
bool b[N];
int maxn,cnt;
bool ff;
ll ans;
bool cmp(ll x,ll y){
	return x>y;
}
int f(ll x){
	for(int i=32;i>=0;i--){
		if((x&(1<<i))>0)return i;
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxn=max(maxn,f(a[i]));
	}
	sort(a+1,a+1+n,cmp);
	int tnt=n;
	for(int i=maxn;i>=0;i--){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(b[j])continue;
			if((a[j]&(1<<i))>0)cnt++;
		}
		if(cnt<m)continue;
		for(int j=1;j<=n;j++){
			if(b[j])continue;
			if((a[j]&(1<<i))==0)b[j]=1;
		}
		ans=(ans|(1<<i));
	}
	cout<<ans;
	return 0;
} 
