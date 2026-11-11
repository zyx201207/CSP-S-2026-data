#include<bits/stdc++.h>
using namespace std;
int const N=5*1e5;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int maxn=0,x;
	for(int i=1; i<=n; i++){
		int sum=0;
		for(int j=1; j<=n; j++){
			sum+=abs(a[i]-a[j]);
			if(sum>m){
				x=j;
				break;
			}
		}
		maxn=max(maxn,x-1);
	}
	cout<<maxn;
	return 0;
}
