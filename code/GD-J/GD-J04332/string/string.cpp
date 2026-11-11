#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,a[N],l,r;
char c[N];
ll ans,len,mid;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	l=1,r=n;
	mid=(len+1)/2;
	while(l<r){
		while(a[l]&&l<r){
			int t=min(a[l],a[r]);
			if(c[l]!=c[r]) ans+=t;
			a[l]-=t;
			a[r]-=t;
			if(!a[r]) r--;
		}
		l++;
	}
	cout<<ans<<'\n';
	return 0;
}

