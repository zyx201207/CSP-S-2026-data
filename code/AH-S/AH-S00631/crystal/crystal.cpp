#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e5+10;
LL n,m,a[N],cnt,qz[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		LL standard=a[i],sum=standard*x-(qz[i]-qz[i-x]);
		if(sum<=m)
			return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		qz[i]=qz[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	cout<<l<<endl;
	return 0;                                        
}
