#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,mx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1,s=0;
	while(r<=n){
		if(s<=m){
			mx=max(mx,r-l+1);
			r++;
			s+=(a[r]-a[r-1])*(r-l);
		}
		else{
			l++;
			s-=a[r]-a[l-1];
		}
	}
	cout<<mx;
	return 0;
}
