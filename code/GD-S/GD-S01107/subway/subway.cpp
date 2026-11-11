#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
long long n , m , q , w[M] , d , x , y , A[510]; 
void DFS(char h , long long v){
	if(h=='z'){
		for(int i=0;i<tuz[])
	}
}
void solve(long long x , long long y){
	long long ans=0 , Z_min[m+1] , C_min[n+1];
	ans+=(w[x]+w[y]);
	for(int i=1;i<=m;i++){
		Z_min[i]=0x3f3f3f3f;
	}
	for(int i=1;i<=n;i++){
		C_min[i]=0x3f3f3f3f;
	}
	Z_min[x]=0;
	DFS('z' , x);
	ans+=Z_min[y];
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin>>n;
	cin>>n>>m>>d>>q;
	vector<vector<pair<int , int>>> tuz(m+1);
	vector<vector<pair<int , int>>> tuc(n+1);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>A[i];
		int k , T;
		for(int j=1;j<=A[i];j++){
			cin>>k>>T;
			tuz[k].push({T , i});
			tuc[i].push({T , k});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		solve(x , y);
	}
	
	return 0;
}
//Oct31==Dec25?
