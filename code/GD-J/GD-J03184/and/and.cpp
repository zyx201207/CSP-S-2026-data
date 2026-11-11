#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N=2e5+5;
int n,k,ma;
ll ans;
struct node{
	ll a;
	int co[35],l;
}t[N];
inline ll read(){
	ll x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10LL+(c-'0');
		c=getchar();
	}
	return x;
}
inline void write(ll x){
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
inline void chk(int i){
	ll x=t[i].a;
	int sum=0;
	while(x>0){
		sum++;
		t[i].co[sum]=x%2;
		x/=2;
	}
	t[i].l=sum;
	ma=max(ma,sum);
}
inline ll POW(ll x,int y){
	if(y==0) return 1;
	ll ans=1;
	while(y>1){
		if(y&1) ans*=x;
		y>>=1;
		x*=x;
	}
	return x*ans;
}
int main(){
//	freopen("and4.in","r",stdin);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(); k=read();
	for(int i=1;i<=n;i++){
		t[i].a=read();
		chk(i);
	}
	sort(t+1,t+1+n,[](node x,node y){
		return x.a>y.a;
	});
	multiset<int>s;
	for(int i=1;i<=n;i++) s.insert(i);
	for(int i=ma;i>=1;i--){
		int cou=0;
		for(int j:s){
			if(t[j].co[i]) cou++;
//			cout<<cou<<"\n";
		}
		if(cou>=k){
			multiset<int>st;
			ans+=POW(2LL,i-1);
			for(int j:s){
				if(t[j].co[i]) st.insert(j);
			}
			s=st;
		}
	}
	write(ans);
	return 0;
}
