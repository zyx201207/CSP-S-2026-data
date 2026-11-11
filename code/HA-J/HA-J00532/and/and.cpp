#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],f[N],ff[N],ans,t,p; 
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++){
		f[++t]=a[i]&a[i-1];	
	}
	sort(f+1,f+1+t,cmp);
	for(int i=2;i<=t;i++){
		ff[++p]=f[i]&f[i-1];
	}
	sort(ff+1,ff+1+p,cmp);
	ans=ff[1];
	cout<<ans;
	return 0;
}
