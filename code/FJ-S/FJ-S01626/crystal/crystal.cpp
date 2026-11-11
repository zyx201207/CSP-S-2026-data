#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	char ch=getchar();
	ll x=0,f=1;
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void write(ll x){
	if(x<0) putchar('-');
	x=abs(x);
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
ll n,m,a[500050];
queue<ll> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1);
	q.push(a[1]);
	ll len=1,s=a[1],ans=1;
	for(ll i=1;i<=n;++i){
		while(len*a[i]-s>m&&len>0){
			len--;
			s-=q.front();
			q.pop();
		}
		len++;
		q.push(a[i]);
		s+=a[i];
		ans=max(ans,len);
	}
	cout<<ans<<endl;
	return 0;
} 
