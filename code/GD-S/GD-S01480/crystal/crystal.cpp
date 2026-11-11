#include<bits/stdc++.h>
using namespace std;
long long a[1000006];
long long q[1000006];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int num=0,ans=0,maxn=0;
	int l=1,r=1;
	while(l<=n&&r<=n){
		int l0=r-l+1;
		num+=(l0-1)*(a[r]-a[r-1]);
		if(num<=m){
			r++;
			ans++;
		}
		else{
			num-=(a[r]-a[l]);
			l++;
			ans--;
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
}
