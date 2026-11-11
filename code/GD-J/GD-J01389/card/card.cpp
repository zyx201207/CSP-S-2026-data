#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,a[10000],b[10000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    b[i]=i;
    }
	for(int i=1;i<=m;i++)
	    cout<<b[i]<<" ";
}
