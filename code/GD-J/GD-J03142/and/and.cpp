#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200010];	
ll n,m,maxn=0;
void f(ll m1,ll k,ll sum,ll l){
	if(k==n&&m1!=0){
		maxn=max(maxn,sum);
		cout<<maxn;
	}
	if(m1==0){
		maxn=max(maxn,sum);
		return f(m-1,l+1,a[l+1],l+1);
	}
	for(ll i=k+1;i<=n;i++){
		return f(m1-1,i,a[i]&sum,l);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	f(m-1,1,a[1],1);
	return 0;
} 

