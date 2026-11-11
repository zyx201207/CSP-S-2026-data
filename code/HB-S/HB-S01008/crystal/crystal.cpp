#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
int n,m;
int a[N],s[N],b[N],res;
int dis(int i,int j){
	int p=(j-i)*a[j];
	int q=s[j-1]-s[i-1];
	return p-q;
}
bool check(int mid){
	int flag=0;
	for(int i=mid; i>=1; i--){
		if(dis(i,mid)<=m){
			if(mid-i+1>res) res=mid-i+1,flag=1;
		}
	}
	return flag;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++){
		s[i]=s[i-1]+a[i];
	}
	int l=0,r=n;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	cout<<res;
	return 0;
}
