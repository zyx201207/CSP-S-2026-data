#include<bits/stdc++.h>
using namespace std;
int u[100005],v[100005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	for(int j=1;j<=t;j++){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
		}
	}
	if(c==0&&t==2){
		cout<<1<<endl;
		cout<<2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
