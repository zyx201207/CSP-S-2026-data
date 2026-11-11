#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int a[N];
int n,m,ans=0,c;
bool check(int x){
	int cnt=0;
	for(int i=x-1;i>=1;i--){
		cnt+=a[x]-a[i];
		if(cnt>m){
			if(x-i>ans){
				c=a[x];
				ans=x-i;
			}
			return false;
		}
	}
	if(ans<x){
		ans=x;
		c=a[x];
	}
	return true;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else {
			r=mid;
		}
	}
	int cnt=0,z=0;
	for(int i=n;i>=1;i--){
		if(a[i]>c)continue;
		cnt+=c-a[i];
		if(cnt>m)break;
		else z++; 
	}
	cout<<z;
	return 0;
} 
