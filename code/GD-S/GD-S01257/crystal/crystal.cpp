#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
long long b[500005];
long long mb=0;
bool check(int xb,int zd){
	long long cha=(zd-xb+1)*mb-(b[zd]-b[xb-1]);
	return cha<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	int maxx=1;
	for (int i=2;i<=n;i++){
		int l=1,r=i,ans=0;
		mb=a[i];
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				ans=mid;
				r=mid-1;
			}
			else {
				l=mid+1;
			}
		}
		maxx=max(maxx,i-ans+1);
	}
	cout<<maxx;
    
	return 0;
} 
