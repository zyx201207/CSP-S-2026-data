#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int max1=-10000000000000;
		int n,k;
		cin>>n>>k;
		for(int j=1;j<n;j++){
			int u,v;
			cin>>u>>v;
			max1=max(max1,v-u);
		}		
		cout<<max1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
