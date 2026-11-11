#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],ans[500005];
bool fl[500005];
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
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();
	m=read();
	for(ll i=1;i<=n;i++)a[i]=read();
	for(ll i=1;i<=n;i++){
		deque<ll> q;
		for(ll j=i;j<=n;j++){
			if(fl[a[j]]==0){
				fl[a[j]]=1;
				q.push_back(a[j]);
			}
			while(q.back()!=a[j]){
				fl[q.back()]=0;
				q.pop_back();
			}
		}
		for(int j=1;j<=m;j++){
			if(fl[j]){
				ans[j]++;
				fl[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
