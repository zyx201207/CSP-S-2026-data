#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],ans,cnt,ct;
deque<ll> q;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(ll i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ct+=cnt*(a[i]-a[i-1]);
		while(!q.empty()&&ct>m){
			ct-=(a[i]-q.front());
			cnt--;
			q.pop_front();
		}
		cnt++;
		q.push_back(a[i]);
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
