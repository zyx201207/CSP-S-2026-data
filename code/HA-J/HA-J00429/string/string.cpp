/*永远铭记------丁浩文------史诗级大帅哥*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
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
const int N=2e5+999;
int n;
ll a[N],sum,mid;
char c[N];
//io
void input(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		sum+=a[i];
		cin>>c[i];
	}
	mid=sum/2;
}
//solve
void solve(){
	int q=0,h=n+1;
	ll qcnt=0,hcnt=0;
	ll qsum=0,hsum=0;
	ll ans=0;
	while(qsum<mid||hsum<mid){
		ll ed=0;
		if(qcnt==0&&qsum<mid){
			ed=qsum;
			qsum=min(qsum+a[++q],mid);
			qcnt=qsum-ed;
		}
		if(hcnt==0&&hsum<mid){
			ed=hsum;
			hsum=min(hsum+a[--h],mid);
			hcnt=hsum-ed;
		}
		ll minn=min(hcnt,qcnt);
		if(c[q]!=c[h])ans+=minn;
		qcnt-=minn;
		hcnt-=minn;
	} 
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);


	input();
	solve();
	return 0;
}

