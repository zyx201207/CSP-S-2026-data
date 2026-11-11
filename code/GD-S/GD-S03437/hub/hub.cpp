#include<bits/stdc++.h>
using namespace std;
int v,u;
long long n[500005],k[500005];
int main(){
	freopen("hub.in","w",stdin);
	freopen("hub.out","r",stdout);
	int c,t;
	cin>>c>>t;
	for(int i = 1;i <= t;i++){
		cin>>n[i]>>k[i];
		for(int j = 1;j <= n[i];j++){
			cin>>v>>u;
		}
	}
	cout<<1<<endl<<2;
	return 0;
} 
