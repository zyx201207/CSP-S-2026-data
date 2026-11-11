#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010],pre[500010],pos[500010];
bool check(int x){
	for(int i=x;i<=n;i++){
		if(pre[i]-(pos[i-x])+(i-x)*(a[n]-a[i])<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	pos[1]=pre[1]=0;
	for(int i=2;i<=n;i++)
		pre[i]=pre[i-1]+(a[i]-a[i-1])*(i-1);
	pos[1]=a[n]-a[1];
	for(int i=2;i<=n;i++){
		pos[i]=pos[i-1]+a[n]-a[i];
	}
	int l=1,r=n,k=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			k=mid;
		}
		else r=mid-1;
	}
	cout<<k;
	return 0;
} 
