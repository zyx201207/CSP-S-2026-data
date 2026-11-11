/*永远铭记------丁浩文------史诗级大帅哥*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define pii pair<int,int>
#define pll pair<ll,ll>
ll read(){
	char ch=getchar();
	int f=1;
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
const int N=5e5+999;
int n;
ll a[N];
ll m;
//io
void input(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
}
//solve
ll sum;
ll ans,now;
void solve(){
	sort(a+1,a+n+1);
	for(ll i=1,j=1;i<=n;i++){
		sum+=a[i];
		while(((i-j+1)*a[i])-sum>m){
			sum-=a[j];
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);


	
	input();
	solve();
	return 0;
}

