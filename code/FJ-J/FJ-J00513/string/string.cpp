#include<bits/stdc++.h>
using namespace std;
int n,a[200001],l,r,x;
long long ans;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1;
	r=n;
	while(r-l>=1){
		if(c[l]==c[r]){
			x=min(a[l],a[r]);
			a[l]-=x;
			a[r]-=x;
			if(!a[l])l++;
			if(!a[r])r--;
		}
		else{
			x=min(a[l],a[r]);
			ans+=x;
			a[l]-=x;
			a[r]-=x;
			if(!a[l])l++;
			if(!a[r])r--;
		}
	}
	cout<<ans;
	return 0;
}
