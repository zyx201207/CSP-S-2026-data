#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int u[200002],v[200002];
int d[200002];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int r=0;r<t;r++){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
			d[i]=abs(u[i]-v[i]);
		}
		sort(d+1,d+n);
		cout<<d[k]<<endl;
	}
	return 0;
} 
