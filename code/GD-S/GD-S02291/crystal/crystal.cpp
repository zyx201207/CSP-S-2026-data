#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=5e5+2;
int a[N]; 
pair<bool,int> check(int mid,int n,int m){
	int cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if(mid-a[i]<0){
			break;
		}
		cnt+=(mid-a[i]),sum+=1;
	}
	return {cnt<=m,sum};
}

int bin(int n,int m){
	int l=a[1],r=a[n],ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		auto data=check(mid,n,m);
		if(data.first){
			ans=max(ans,data.second);
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}	
	return ans;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+n+1);
	cout<<bin(n,m);
	return 0;
}

