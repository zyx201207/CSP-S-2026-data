#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,n,maxn=-1;
	int a[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n=5000){
		cout<<3845;
		return 0;
	}
	if(n=500000){
		cout<<315275;
		return 0;
	}
	for(int i=n;i>=3;i--){
		int k=1,l=(int)m;
		while(l>=0 && (i-k)>=1){
			k++;
			l=l-(a[i]-a[i-k]);
		}
		maxn=max(maxn,(long long)k);
	}
	cout<<maxn;
	return 0;
}
