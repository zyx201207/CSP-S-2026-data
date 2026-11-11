#include <bits/stdc++.h>
using namespace std;

const int N=2e9;
char c[N];
long long k=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		int x;
		char ch;
		cin>>x>>ch;
		fill(c+k,c+k+x,ch);
		k+=x;
	}
	
	long long s=1ll*k/2;
	long long ans=0;
	for(int i=0; i<s; i++){
		if(c[i]!=c[k-i-1]) ans++;
	}
	cout<<ans<<'\n';
	return 0;
}
/*6
1 a
1 c
3 b
1 a
3 c
1 a*/

