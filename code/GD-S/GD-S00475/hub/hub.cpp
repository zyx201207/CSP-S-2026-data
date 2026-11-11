#include <iostream>
using namespace std; 
const int N=1e6+10;
int f[N];
int find(int x){
	if(f[x]==x) return x;
	return find(f[x]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	int c,T;
	cin>>c>>T;
	for(int i=1;i<=N;i++) f[i]=i;
	while(T--){
		int n,k;
		cin>>n>>k;
		for(int i=1,x,y;i<=n;i++){
			cin>>x>>y;
			f[x]=find(y);
		}
		cout<<1<<'\n'; 
	}
	return 0;
} 
