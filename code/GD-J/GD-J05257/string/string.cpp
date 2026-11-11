#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5;
int a[N+10];
char c[N+10];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	ll len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
//	ll l=0,r=0;
	ll ans=0;
	int bl=1,br=n;
	while(bl<br){
		int minlen=min(a[bl],a[br]);
		if(c[bl]!=c[br])ans+=minlen;
		
		if(minlen==a[bl])bl++;
		else a[bl]-=minlen;
		
		if(minlen==a[br])br--;
		else a[br]-=minlen;
	}
	cout<<ans;
	return 0;
}
//6 1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b
//3 2 a 2 b 1 c
