#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5,M=5e3+3;
int a[N],p[32]={1},l[N];
//int po(int x){
//	int l=0,r=31,mid;
//	while(l<=r){
//		mid=(l+r)/2;
//		if(x>=p[mid])
//	}
//}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=30;++i)p[i]=p[i-1]*2;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	} 
	if(m==1)cout<<0;
	else if(m==n){
		int ans=0;
		for(int i=2;i<=n;++i){
			for(int j=0;j<=30;++j){
				l[j]+=a[i]%2;
				a[i]/=2;
			}
		}
		for(int i=0;i<=30;++i){
			if(l[i]>=2)ans+=p[i];
		}
		cout<<ans;
	}else {
		if(m==2)cout<<a[n-1];
		else cout<<a[n];
	}
	return 0;
}

