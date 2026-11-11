#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m,a[N],pre[N];
bool check(int l,int r){
	ll sum=a[r]*(r-l+1)-(pre[r]-pre[l-1]);
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	pre[0]=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n,t=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(i,mid)){
				t=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		ans=max(ans,t-i+1);
	}
	cout<<ans;
	return 0;
} 
