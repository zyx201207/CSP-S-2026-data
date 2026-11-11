#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define N 200010

struct Node{
	ll l,r;
	char c;
};
Node a[N];

ll n,ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;ll sum=1;
	for(int i=1;i<=n;i++){
		ll num;char x;
		cin>>num>>x;
		a[i].l=sum;
		a[i].r=sum+num-1;
		a[i].c=x;
		sum+=num;
	}
	ll mid=sum/2,id=1,rid=n;
	while(a[id].l<=mid){
		sum=sum-(a[id].r-a[id].l+1);
		while(a[rid].l>=sum){
			if(a[rid].c!=a[id].c) ans=ans+(a[rid].r-a[rid].l+1);
			rid--;
		}
		if(a[rid].r>sum-1){
			if(a[rid].c!=a[id].c) ans+=a[rid].r-sum+1;
			a[rid].r=sum-1;
		}
		id++;
	}
	cout<<ans;
	return 0;
}
