#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5*5+5;
struct node{
	ll vl;
	int sum;
};
int n;
ll m;
ll a[N],c[N];

bool cmp(int x,int y){
	return x<y;
}
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int l,r,mid;
	for(int i=1;i<=n;i++){
		l=1;
		r=i-1;
		while(l<=r){
			mid=(l+r)>>1;
			ll k=c[i]-(a[i]-a[mid-1])*(mid-1)-c[mid-1];
			if(k<=m){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
