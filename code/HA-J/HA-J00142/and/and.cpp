#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,sum,flag;
struct node{
	ll x;
	ll id;
}a[200005];
bool cmp(node a,node b){
	if(a.id==b.id) return a.x>b.x;
	return a.id>b.id;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		if(a[i].x!=i-1) flag=1;
		int ans=0;
		ll x=a[i].x;
		while(x){
			if(x&1) ans++;
			x>>=1;
		}
		a[i].id=ans;
	}
	
	ll y=n;
	int cnt=0;
	while(y!=0){
		y>>=1;
		cnt++;
	}
	if(n==pow(2,cnt-1)&&!flag){
		sum=a[n].x;
		for(int i=1;i<=m;i++){
			sum&=a[n-i+1].x;
		}
		cout<<sum;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	sum=a[1].x;
	for(int i=1;i<=m;i++){
		sum&=a[i].x;
	}
	cout<<sum;
	
	
	return 0;
}

