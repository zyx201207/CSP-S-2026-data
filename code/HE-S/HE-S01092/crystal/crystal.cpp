#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int b[500005];
bool check(int x,int y){
	if((a[y]*(y-x+1)-(b[y]-b[x-1]))>m) return false;
	else return true; 
}
int ef(int x){
	int l=1,r=n,best=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(x+mid-1<=n && check(x,x+mid-1)){
			best=mid;
			l=mid+1;
		} 
		else r=mid-1;
	}
	return best;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		if(a[i-1]-a[i-2]!=a[i]-a[i-1]){
			f=0;
			break;
		}
	}
	if(f){
		for(int l=n;l>=1;l--){
			if(check(1,l)){
				cout<<l;
				return 0;
			}
		}
	}
	int mx=1;
	for(int i=1;i<=n;i++){
		mx=max(mx,ef(i));
	}
	cout<<mx;
	return 0;
} 
