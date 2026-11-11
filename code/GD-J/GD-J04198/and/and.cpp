#include<bits/stdc++.h>
using namespace std;
int n,m,a[200007];
bool check(int mid){
	int cnt=0;
	for(int i=1;i<=n;i++){
		int s=a[i]&mid;
		if(s>=mid)cnt++;
	}
	return cnt>=m;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=0,r=1;
	for(int i=1;i<=30;i++)r*=2;
	while(r-l>1){
		int mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}
