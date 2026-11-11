#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],pre[500005];
bool check(int mid){
	if(a[mid]*mid-pre[mid]<=m) return true;
	else return false;
}int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	 
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
