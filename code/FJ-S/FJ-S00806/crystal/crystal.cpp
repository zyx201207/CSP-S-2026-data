#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int n;
ll m,a[(int)(5e5+5)],s[(int)(5e5+5)];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;++i)
		cin >> a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;++i)
		s[i]=s[i-1]+a[i];
	int j=1;ll ans=0;
	for (int i=1;i<=n;++i){
		if (1LL*a[i]*(i-j+1)-(s[i]-s[j-1])>m) ++j;
		ans=max(ans,(ll)(i-j+1));
	} cout << ans;
	return 0;
}

//OctCrystal==DecKrustal?
//Oct31==Dec25?
//By luogu@YzxLeaf.26/10/31.
//freopen("crystal.in","w",stdin);
//freopen("crystal.out","r",stdout);
//freeopen froepen
//freopen("crystal1.in","r",stdin);
//freopen("crystal2.in","r",stdin);
//freopen("crystal3.in","r",stdin);
//freopen("crystal4.in","r",stdin);
//freopen("crysta1.in","r",stdin);
