#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll a[N],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=100000;i++){
		int k=i,cnt=0,p=m;
		for(int j=1;j<=n;j++){
			if(a[j]>k) break;
			if(k-a[j]<=p) p-=(k-a[j]),cnt++; 
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
