#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(b[a[i]]==0){
			b[a[i]]+=b[a[i]-1];
		}
		b[a[i]]++;
		
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
