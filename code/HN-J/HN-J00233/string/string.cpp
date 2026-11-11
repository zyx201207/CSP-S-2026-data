#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
vector<int> a;
vector<char> c;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	a=vector<int> (n+1,0);
	c=vector<char> (n+1,0);
	for (int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	long long ll=a[l],rr=a[r];
	while (l<r){
		if (ll>rr){
			if (c[l]!=c[r]){
				ans+=rr;
			}
			ll-=rr;
			r-=1;
			rr=a[r];
		}else{
			if (c[l]!=c[r]){
				ans+=ll;
			}
			rr-=ll;
			l+=1;
			ll=a[l]; 
		}
	}
	cout<<ans;
	return 0;
}

