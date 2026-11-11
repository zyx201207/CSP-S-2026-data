#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
int n,m,l,r,maxx=INT_MIN;
int a[N];
int d[N];
bool cmp(int i,int j){
	int sum=d[j]-d[i]-(a[j]-a[i])*(i-1);
	if(sum<=m) return 1;
	else return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
//	for(int i=1;i<=n;++i){
//		cout<<(int)d[i]<<endl;
//	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		d[i]=d[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;++i){
		int l=i-1,r=n;
		while(l+1<r){
			int mid=(l+r)/2;
			if(cmp(i,mid)) l=mid;
			else r=mid;
//			cout<<l<<' '<<r<<endl;
		}
//		cout<<l<<' '<<r<<endl;
		maxx=max(l-i+1,maxx);
	}
	cout<<maxx<<endl;
	return 0;
}

