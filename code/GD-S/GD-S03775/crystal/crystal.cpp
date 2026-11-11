#include<bits/stdc++.h>
using namespace std;
#define FILE "crystal"
int n;
long long m;
long long a[600001],summ[600001];
int ids[600001];
int main(){
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		ids[i]=i;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		summ[i]=summ[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		//(j,i]组团
		//(i-j)*a[i]-summ[i]+summ[j]<=m
		//=i*a[i]-summ[i]-(j*a[i]-summ[j])<=m
		//最小的满足j*a[i]-summ[j]>=i*a[i]-summ[i]-m的j
		//最小的满足a'[j]>=a[i]-m的j
		int ll=0,rr=i;
		while(ll<rr){
			int j=(ll+rr)>>1;
			if((i-j)*a[i]-summ[i]+summ[j]<=m){
				rr=j;
			} else{
				ll=j+1;
			}
		}
		ans=max(ans,i-rr);
	}
	cout << ans;
	return 0;
}
/*
栈内元素单调递增 
*/
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
