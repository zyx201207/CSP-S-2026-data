#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans,a[N],p[N];
int check(int x){
	int t=0,mm=m,bns;
	for(int i=1;i<=n && a[i]<=a[x];i++) t++,p[i]=a[x]-a[i];
	sort(p+1,p+t+1);
	for(int i=1;i<=t;i++){
		if(p[i]<=mm) mm-=p[i],bns++;else break;
	}
	return bns;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) ans=max(ans,check(i));
	cout<<ans;
	
	return 0;
} 
