#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector <int> v[100010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(k<=2){
			cout<<1<<"\n";
		}else{
			cout<<(k+1)/2<<"\n";
		}
	}
	return 0;
}
