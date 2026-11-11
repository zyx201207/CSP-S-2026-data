#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,a[N],b[N],c[N];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie();cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],b[a[i]]++;
	for(int i=1;i<=n;i++){
		if(b[i]) b[i]=1;
		else b[i]=1;
		for(int j=1;j<=n;j++) if(a[i]==i) c[i]++;
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}
