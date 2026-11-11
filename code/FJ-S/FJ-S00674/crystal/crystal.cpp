#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
int n,m;
int a[500010];
int s[500010];
bool f(int x){
	int lf=1;
	for(int i=x;i<=n;i++){
		int l=i-x+1,r=i;
		if(((x-1)*a[r]-(s[r-1]-s[l-1]))<=m) lf=0;
	}
//	cout<<endl;
	if(lf==0) return 1;
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	int l=1,r=n;
	while(l<r){
		
		int m=(l+r+1)/2;
//		cout<<l<<" "<<r<<" "<<m<<endl;
		if(f(m)) l=m;
		else r=m-1;
		
	}
	cout<<l;
	return 0;
}
