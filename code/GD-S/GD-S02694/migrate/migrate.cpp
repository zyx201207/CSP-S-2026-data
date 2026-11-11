#include<iostream>
using namespace std;
int x[10000000];
int dfs(int n,int d){//n=总路程，d=一次飞多远 
	if(n<=0) return 0;
	for(int i=1;i<=d;i++){
		if(n==i) return 1+dfs(n-1,d);
	}
	int y=0;
	for(int i=1;i<=d;i++){
		y+=dfs(n-i,d);
	}
	return y;
}
int f(int n,int d){
	int y=0;
	for(int i=2;i<=n;i++){
		if(dfs(n,d)==2) y++;
	}
	return y;
}

int main(){
	int c,t;
	cin>>c>>t; 
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[i-1];
		}
		cout<<f(n,d);
	}
	return 0;
}

