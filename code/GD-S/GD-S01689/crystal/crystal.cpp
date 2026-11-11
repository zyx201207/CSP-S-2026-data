#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int mx=0;
bool f=true;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int t=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=t){
			f=false;
		}
	}
	if(f){
		for(int i=1;i<=n-1;i++){
			if(t*i*(i+1)/2>m){
				cout<<i;
				return 0;
			}
		}
	}
	for(int i=2;i<=n;i++){
		int sum=1,s=0;
		for(int j=i-1;j>=1;j--){
			s+=a[i]-a[j];
			sum++;
			if(s>m){
				sum--;
				j=1;
			}
		}
		mx=max(sum,mx);
	}
	cout<<mx;
	return 0;
}
