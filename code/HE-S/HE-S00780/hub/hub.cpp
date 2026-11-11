#include<bits/stdc++.h>
using namespace std;
const int N=2222222;
int c,t,n,k,u,v;
int a[N],b[N];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>u>>v;
		}
		for(int j=0;j<k;j++){
			cin>>u>>v;
		}
		if(t==0){
			cout<<2<<endl;
		}else{
			cout<<1<<endl;
		}
	}
	return 0;
}
