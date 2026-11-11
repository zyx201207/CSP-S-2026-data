#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,g=0;
	cin>>n;
	long long a[n+5];
	char c[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		int j=min(a[l],a[r]);
		if(c[l]!=c[r]){
			g+=j;
		}
		if(r-l<=1) break;
		a[l]-=j;a[r]-=j;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<g;
	return 0;
}
