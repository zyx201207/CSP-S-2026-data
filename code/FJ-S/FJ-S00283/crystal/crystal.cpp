#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],n,m,anss,q[500005];
bool check(int x,int y){
	int hf=(y-x+1)*a[y]-q[y]+q[x-1];
	if(m>=hf)return true;
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				r=mid-1;
				ans=i-mid+1;
			}
			else{
				l=mid+1;
			}
		}
		anss=max(ans,anss);
	}
	cout<<anss;
	return 0;
}

