#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=2e6+5;
ll c,t;
ll n,d;
ll a[MAXN];
int l[MAXN],r[MAXN];
ll num1[MAXN],num2[MAXN];
ll tot[MAXN];
stack<ll> st1,st2;
ll ans;
void read(ll &x){
	x=0;
	bool flag=false;
	while(true){
		char tmp=getchar();
		if(tmp=='-'){
			flag=true;
		}
		else if(tmp>='0'&&tmp<='9'){
			x=x*10+tmp-'0';
		}
		else{
			break;
		}
	}
	if(flag){
		x=-x;
	}
}
void init(){
	while(!st1.empty()){
		st1.pop();
	}
	while(!st2.empty()){
		st2.pop();
	}
	for(int i=1;i<=n;i++){
		num1[i]=num2[i]=0;
	}
	ans=0;
}
void build(){
	int now=1;
	for(int i=1;i<=n;i++){
		while(now<i&&a[i]-a[now]>d){
			now++;
		}
		l[i]=now;
	} 
	now=n;
	for(int i=n;i;i--){
		while(now>i&&a[now]-a[i]>d){
			now--;
		}
		r[i]=now;
	}
}
void solve(){
	for(int i=1;i<=n;i++){
		tot[i]=0;
	}
	for(int i=n;i;i--){
		if(l[i]==i){
			continue;
		}
		if(l[i]<i-1){
			num1[l[i]]++;
		}
		if(l[i]<i-1&&r[l[i]+1]==i){
			num1[l[i]]+=tot[i];
		}
		tot[l[i]]++;
		if(r[l[i]]==i){
			tot[l[i]]+=tot[i];
		}
	}
	for(int i=1;i<=n;i++){
		tot[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(r[i]==i){
			continue;
		}
		if(r[i]>i+1){
			num2[r[i]]++;
		}
		if(r[i]>i+1&&l[r[i]-1]==i){
			num2[r[i]]+=tot[i];
		}
		tot[r[i]]++;
		if(l[r[i]]==i){
			tot[r[i]]+=tot[i];
		}
	}
}
void print(){
	for(int i=1;i<n;i++){
		ans+=num1[i]*num2[i+1];
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c);
	read(t);
	while(t--){
		read(n);
		read(d);
		init(); 
		for(int i=1;i<=n;i++){
			read(a[i]);
		}
		build();
		solve();
		print();
	}
}
