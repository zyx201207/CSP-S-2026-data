#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int p[t];
	for(int j=0;j<t;j++){
		int n,k;
		cin>>n>>k;
		int u[n],v[n];
		for(int i=0;i<n-1;i++){
			cin>>u[i]>>v[i];
		}
	}
	for(int i=0;i<t;i++){
		cout<<p[i];
	}
	return 0;
}
//1-----2-----3-----4-----5
//
// 	    8	        5
//		|  	        |
//6-----3-----1-----2-----4
//		|
//      7-----9-----10
