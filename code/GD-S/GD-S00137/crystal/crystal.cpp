#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500010],p[500010];
int n,m;
bool check1(int d,int r,int x){
	return p[r]-p[x-1]-r*d+x*d-d<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]+a[n]-a[i];
		//cout<<a[i]<<' '<<p[i]<<'\n';
	}
	int mx=1;
	for(int r=1;r<=n;r++){
		int d=a[n]-a[r];
		int l1=1,r1=r;
		while(l1<r1){
			int mid=(l1+r1)>>1;
			//cout<<check1(d,r,mid)<<'\n';
			if(check1(d,r,mid)){
				r1=mid;
			}else{
				l1=mid+1;
			}
		}
		//cout<<'\n';
		mx=max(mx,r-l1+1);
	}
	cout<<mx;
	
	return 0;
} 
