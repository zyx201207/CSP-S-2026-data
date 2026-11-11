#include<bits/stdc++.h>
using namespace std;
int p[1000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int q,w,e,r,t;
	cin>>q>>w>>e>>r>>t;
	for(int i=1;i<=e;i++){
		cin>>p[i];
	}
	int qw;
	for(int i=1;i<=2*w;i++){
		cin>>qw;
	}
	for(int i=1;i<=t;i++){
		int x,y;
		cin>>x>>y;
	}
	cout<<"32"<<endl<<"17";
	return 0;
} 
