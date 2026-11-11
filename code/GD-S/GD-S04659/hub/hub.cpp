#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,d;
int a[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i];
		}
	}
}
