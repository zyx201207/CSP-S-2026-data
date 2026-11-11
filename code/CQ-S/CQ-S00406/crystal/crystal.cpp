#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int a[500010];
int num;

int o(int x){
	int ans=0;
	for(int i=1;i<x;i++){
		ans=ans+a[i];
	}
	for(int i=x;i<=n;i++){
		ans=ans+a[i];
		ans=ans-a[i-x];
		if(a[i]*x-ans<=m) return 1;
	}
	return 0;
}

signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int L=1,R=n;
	
	while(L<R){
		int mid=(L+R+1)/2;
		if(o(mid)==1) L=mid;
		else R=mid-1;
		num++;
		if(num==100) break;
	}
	cout<<L;
	return 0;
} 
