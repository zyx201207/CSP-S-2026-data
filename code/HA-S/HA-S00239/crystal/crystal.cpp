#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=5e5+5;
ll n,m,a[maxn],tail,l,sum[maxn],head;
int jdz(ll x){
	if(x<0)return x;
	return x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	sum[0]=0;
	l=2;
	head=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	while(tail<n){
		tail=head+l-1;
		if(a[tail]*l-(sum[tail]-sum[head-1])<=m){
			tail++;
			l++;
		}else{
			head++;
		}
	}
	cout<<l-1<<'\n';
	return 0;
}
