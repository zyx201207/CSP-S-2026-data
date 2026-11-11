#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int b[500005];
int c[500005];//´Óa[1]¼Óµ½a[i]
int d[500005];// a[1]+2*a[2]+...+i*a[i]
int n,m;
int ans=1;
bool check(int i,int mid){
	int cnt=(d[mid]-d[i])-(i-1)*(c[mid-1]-c[i]);
	return cnt<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];	
	}
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+b[i];
		d[i]=d[i-1]+(i-1)*b[i];
	}
//	for(int i=1;i<=n;i++){
//		cout<<c[i]<<' ';
//	}cout<<'\n';
//	for(int i=1;i<=n;i++){
//		cout<<d[i]<<' ';
//	}cout<<'\n';
	
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<r){
			int mid=(l+1+r)/2;
			if(check(i,mid)){
				l=mid;
			}
			else r=mid-1;
		}
		ans=max(ans,l-i+1);
//		cout<<i<<' '<<q<<'\n';
	}
	cout<<ans;
} 
