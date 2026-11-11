#include<bits/stdc++.h>
using namespace std; 
#define int long long

const int N = 5*1e5+10;
int n,m,a[N];

bool check(int x){
	int u=0;
	for(int i=1;i<=x;i++){
		u+=a[x]-a[i];
	}
	//cout<<" 	x= "<<x<<" u="<<u<<endl;
	if(u<=m) return 1;
	else return 0;
}

int find(){
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		//cout<<" l="<<l<<" r="<<r<<" mid="<<mid<<endl;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	return r;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cout<<find();
} 
