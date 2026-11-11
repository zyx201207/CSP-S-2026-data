#include<bits/stdc++.h>
using namespace std;
int a[200001];
char c[200001];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	int n;
	long long ans=0;
	char cc='a';
	cin>>n;
	for(int g=1;g<=n;++g)
		cin>>a[g]>>c[g];
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r])
			ans+=min(a[l],a[r]); 
		int _b = a[l];
		a[l]=max(0,a[l]-a[r]);
		a[r]=max(0,a[r]-_b);
		if(a[l]==0)++l;
		if(a[r]==0)--r;
	}
	cout<<ans;
	return 0;
} 
