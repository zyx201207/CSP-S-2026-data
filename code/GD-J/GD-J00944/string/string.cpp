#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
ll a[N];
char b[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i];
	}
	ll ans=0;
	int aj=0,ah=0;
	char ajd='a',ahd='a';
	int ij=0,ih=n+1;
	while(ij<ih-1){
		if(aj){
			ih--;
			ah=a[ih];
			ahd=b[ih];
		}
		else if(ah){
			ij++;
			aj=a[ij];
			ajd=b[ij];
		}
		else{
			ij++;
			ih--;
			aj=a[ij];
			ah=a[ih];
			ajd=b[ij];
			ahd=b[ih];
		}
		if(ajd==ahd){
				int k=min(aj,ah);
				aj-=k;
				ah-=k;
			}
			else{
				int k=min(aj,ah);
				aj-=k;
				ah-=k;
				ans+=k;
			}
	}
	cout << ans;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	return 0;
} 
