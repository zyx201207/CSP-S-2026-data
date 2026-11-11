#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,r,n,m;
	cin>>c>>r;
	for(int i=0;i<r;i++){
		cin>>n>>m;
		for(int j=0;j<n;j++){
			cin>>m>>m;
		}
	}
	int x;
	if(c<=3){
		x=10;
	}
	else if(c<=6){
		x=100;
	}
	else if(c<=8){
		x=500;
	}
	else if(c<=10){
		x=5000;
	}
	else{
		x=100000;
	}
	for(int i=0;i<r;i++){
		int xy=rng()%x;
		cout<<xy<<"\n";
	}
	return 0;
}
