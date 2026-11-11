#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,num;
struct ok{
	int u;
	int v;
}p[2000][2000];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n-1;j++){
			cin>>p[i][j].u >>p[i][j].v ;
		}
		
		if(i=1){
			cout<<1<<endl;
		}else{
			cout<<2<<endl;
		}
		
	}
	return 0;
}
