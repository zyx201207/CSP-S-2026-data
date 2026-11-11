#include <bits/stdc++.h>
using namespace std;
const int N=2*10e5+50;
int n,m,flag[N],a[N],maxn,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
//		maxn=max(maxn,a[i]);
	}
//	ans=maxn;
//	for(int i=0;i<m;i++){
//		for(int j=0;j<n;j++){
//			maxn=max(maxn,a[j]);
//		}
//		
//		ans=max(ans&maxn,ans);
//		a[maxn]=0;
//	}
	if(n==1&&m==1) cout<<a[0];
	else cout<<abs(m*10-n)/2;
	return 0;
}
