#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int cha;
int main(){
	freopen("srystal.in","r",stdin);
	freopen("srystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cha=a[1]-a[0];
	cout<<m/cha;
	return 0;
}

