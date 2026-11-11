#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll c,t,n,d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		cout<<n/d<<endl;
	}
}
