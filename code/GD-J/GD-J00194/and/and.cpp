#include<bits/stdc++.h>
using namespace std;
int n,m;
long long maxx=0,x=0;
vector<long long>a;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(maxx!=max(maxx,a[i]&m)){
			x=a[i];
		}
		maxx=max(maxx,a[i]&m);
	}
	cout<<x;
	return 0;
}
