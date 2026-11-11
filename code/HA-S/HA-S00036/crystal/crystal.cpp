#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll m,a[500011];
ll s[500011];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		a[i]+=1000000000000;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int l=1,ans=0;
	for(int r=1;r<=n;r++){
		while(l<r&&m<a[r]*(r-l+1)-(s[r]-s[l-1])){
			l++;
		}
		if(m>=a[r]*(r-l+1)-(s[r]-s[l-1])) ans=max(ans,r-l+1);
	}
	cout << ans;
	return 0;
}


