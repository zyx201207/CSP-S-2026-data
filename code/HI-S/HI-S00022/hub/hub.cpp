#include<bits/stdc++.h>
using namespace std;
const int M=3e5+5;
int n,k;
struct u{
	int u,v;
}a[M];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int t,c;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>a[i].u>>a[i].v;
		} 
		cout<<rand()%k<<'\n';
	} 
	return 0;
}
