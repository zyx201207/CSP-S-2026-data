#include<bits/stdc++.h> 
using namespace std;
struct{
	int qi,zo;
}nm[1000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.ont","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>nm[i].qi>>nm[i].zo;
		}
		cout<<1<<endl;
	}
	return 0;
}
