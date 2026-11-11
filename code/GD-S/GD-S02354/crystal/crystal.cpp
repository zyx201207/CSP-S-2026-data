#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=500005;
ll a[maxn],b[maxn];
inline ll read(){
	char c=getchar();
	ll ret=0,fx=1;
	if(c=='-')fx=-1,c=getchar();
	while(c<='9' and c>='0'){
		ret=(ret<<3)+(ret<<1)+c-'0';
		c=getchar();
	}
	return ret*fx;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,tmp;
	n=read();
	m=read();
	for(ll i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)b[i]=a[i]+b[i-1];

	ll ans=1;
	for(ll lt=1,re=2;re<=n;re++){
		tmp=(b[lt-1]-b[re-1])+(re-lt)*a[re];
		while(tmp>m){
			lt++;
			tmp=(b[lt-1]-b[re-1])+(re-lt)*a[re];
		}
		if(re-lt+1>ans)ans=re-lt+1;
	}

	cout<<ans;
	return 0;
} 
