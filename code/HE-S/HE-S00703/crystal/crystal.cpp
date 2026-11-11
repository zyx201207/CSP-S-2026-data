#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005];
double m;
bool check(int w){
	double sum=0;
	for(int i=1;i<w;i++){
		sum+=a[w]-a[i];
	}
	if(sum<=m){
		return true;
	}
	else{
		return false;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<a[i];
//	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	if(check(l)){
		cout<<l;
	}
	return 0;
}
