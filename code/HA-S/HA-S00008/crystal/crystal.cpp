#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[2000001];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	int ans=1;
	int l=1,r=1;
	long long k=0;
	while(l<=n && r<=n){
		if(k<=m){
			r++;
			for(int i=l;i<r;i++){
				k+=a[r]-a[r-1];
			}
			if(k<=m)
				if(r-l+1>ans){
					ans=r-l+1;
				}
		}
		if(k>m){
			l++;
			k-=a[r]-a[l-1];
		}
	}
	cout<<ans;
	return 0;
}
