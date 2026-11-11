#include<bits/stdc++.h>
using namespace std;
const int N = 1E5+5;
int a[N];
int c,T,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
	}
	return 0;
}
