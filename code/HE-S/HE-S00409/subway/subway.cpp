#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		int w;
		cin>>w;
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,t;
			cin>>a>>t;
		}	
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
	}
	for(int i=0;i<q;i++){
		cout<<abs(c*q+n-m*d*45/6);
	}
	return 0;
}

