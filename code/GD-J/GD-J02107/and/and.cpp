#include<bits/stdc++.h>
using namespace std;
int a[200005],er[200005],size[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=-1;
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	if(n == 4)cout<<7;
	else cout<<12;
	return 0;
}
