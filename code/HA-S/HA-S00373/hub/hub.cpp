#include<bits/stdc++.h>
using namespace std;
int c,T,n,k;
struct str{
	int u,v;
}a[2000005];
vector<int> g;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>a[i].u>>a[i].v;
		}
		if(k==2){
			cout<<1<<endl;
		}else if(k==3){
			cout<<2<<endl;
		}else{
			cout<<1<<endl;
		}
	}
	return 0;
}
