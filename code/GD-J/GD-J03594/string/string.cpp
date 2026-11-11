#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n;
char c[N];
long long a[N];
long long len,ans,l,r,lenl;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1;
	r=n;
	while(l<r){
		int m=min(a[l],a[r]);
		if(c[l]!=c[r])ans+=m;
		a[l]-=m;
		a[r]-=m;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<ans;
	return 0;
}

