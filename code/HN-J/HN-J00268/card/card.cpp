#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N];
int box[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			box[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<box[i]<<' ';
	}
	return 0;
}
