#include<bits/stdc++.h>
using namespace std;
int a[10500]={0,3,0,1,0,2,1,2,1,1,0,0,2,3,0,1,2,1};
int seed;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	seed=(c*114+t*514+1145)%14;
	while(t--){
		cout<<a[seed]<<'\n';
		seed=(seed*114-114514+1919810)%114514%17;
	}
	return 0;
}
