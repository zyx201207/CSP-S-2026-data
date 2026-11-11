#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int q[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,czs=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,czn=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid)-q[i-1]+q[mid-1]<=m){
				czn=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		czs=max(czs,i-czn+1);
	}
	cout<<czs;
	return 0;
} 
