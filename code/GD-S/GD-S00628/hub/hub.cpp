#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int u[N],v[N]

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			cin>>u[i]>>v[i];
		}
		if(k<=4) cout<<1<<endl;
		else cout<<(k-4)/3+1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
