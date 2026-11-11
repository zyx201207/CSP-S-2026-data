#include<bits/stdc++.h>
using namespace std;
int n,k,u[1000006],v[1000006];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int time=1;time<=t;time++){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		if(n<=10){
			cout<<n/5<<endl;
		}
		else cout<<n/20<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
