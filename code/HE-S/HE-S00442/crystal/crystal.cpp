#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int n,r,l;
long long m,a[N],ans[N],zz[N],anss=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	r=1;
	l=1;
	zz[r]=0;
	ans[r]=1;
	while(zz[r]<=m){
		r++;
		zz[r]=zz[r-1]+ans[r-1]*(a[r]-a[r-1]);
		if(zz[r]>m){
			zz[r]=0;
			break;
		}
		ans[r]=ans[r-1]+1;
		anss=max(anss,ans[r]);
	}
	for(int i=r;i<=n;i++){
		zz[i]=zz[i-1]+ans[i-1]*(a[i]-a[i-1]);
		ans[i]=ans[i-1]+1;
		while(zz[i]>m){
			zz[i]-=(a[i]-a[l]);
			l++;
			ans[i]--;
		}
		anss=max(anss,ans[i]);
	}
	cout<<anss;
	return 0;
} 
