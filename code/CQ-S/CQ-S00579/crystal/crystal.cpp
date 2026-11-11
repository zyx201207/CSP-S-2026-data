#include<bits/stdc++.h>
#define int long long
using namespace std;
void rf(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int n,m,a[500005],b[500005];
bool check(int mid,int x){
	int k=b[x-1]-b[mid-1];
	int t=x-mid;
	int y=a[x]*t-k;
	return y<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	rf();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int mx=INT_MIN;
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid;
		while(l<r){
			mid=(l+r)/2;
			if(check(mid,i)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		mx=max(mx,i-r+1);
	}
	cout<<mx;
	return 0;
}
//luogu uid:946931 :) huguan
