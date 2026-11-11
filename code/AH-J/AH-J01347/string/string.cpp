#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			int k=min(a[l],a[r]);
			a[l]-=k;
			a[r]-=k;
			if(!a[l])++l;
			if(!a[r])--r;
		}
		else{
			int k=min(a[l],a[r]);
			a[l]-=k;
			a[r]-=k;
			ans+=k;
			if(!a[l])++l;
			if(!a[r])--r;
		}
	}
	cout<<ans;
	return 0;
}

