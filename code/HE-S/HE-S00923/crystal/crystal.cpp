#include<bits/stdc++.h>
using namespace std;
long long a[500010],s[500010],n,m,ans;
bool check(int x,int p){
	if((p-x+1)*a[p]<=s[p]-s[x-1]+m) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=0,r=i+1;
		while(l+1!=r){
			int mid=(l+r)>>1;
			if(check(mid,i)) r=mid;
			else l=mid;
		}
		ans=max(1ll*(i-r+1),ans);
	} 
	cout<<ans;
	return 0;
}
