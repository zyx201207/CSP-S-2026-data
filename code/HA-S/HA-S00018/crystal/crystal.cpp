#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 500005

ll n,m,a[MAXN],mid,ne[MAXN],ans;

bool check(){
	for(ll i=1;i<n;i++) if(a[i]!=a[i+1]) return 0;
	return 1;
}

bool check2(){
	ll res=0;
	for(int i=1;i<=n;i++){
		res+=(a[n]-a[i]);
	}
	if(res<=m) return 1;
	else return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(check()==1||check2()==1){
		cout<<n;
		return 0;
	}
	ll temp=ceil(n/2.0);
	mid=a[temp];
	for(ll i=temp+1;i<=n;i++){
		if(a[i]!=mid) break;
		else{
			mid=a[i];
			temp=i;
		}
	}
	for(ll i=1;i<=n;i++){
		ne[i]=mid-a[i];
	}
	for(ll i=1;i<=n;i++){
		if(ne[i]<0){
			break;
		}
		if(m>=ne[i]){
			m-=ne[i];
			ans++;
			a[i]+=ne[i];
		}
	}
	while((a[temp+1]-mid)*temp<=m){
		m-=(a[temp+1]-mid)*temp;
		mid=a[temp+1];
		temp++;
		if(temp==n) break;
	}
	ans+=(temp-ans);
	cout<<ans;
	return 0;
}
