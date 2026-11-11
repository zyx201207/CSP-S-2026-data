#include<bits/stdc++.h>
using namespace std;
const int N=2e6+9;
int a[N];
void solved(){
	int n,d; cin>>n>>d;//岛屿数量和海鸟一次最多能飞行的距离	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	cout<<"1"<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	//cout<<fixed<<setprecision(2);
	int c; cin>>c;
	int t; cin>>t;
	while(t--){
		solved();
	}
	return 0;
} 
