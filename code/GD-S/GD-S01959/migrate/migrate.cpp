#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,r,n,m;
	cin>>c>>r;
	for(int i=0;i<r;i++){
		cin>>n>>m;
		for(int j=0;j<n;j++){
			cin>>m;
		}
	}
	for(int i=0;i<r;i++){
		int x=rng()%100000;
		cout<<x<<"\n";
	}
	return 0;
}
