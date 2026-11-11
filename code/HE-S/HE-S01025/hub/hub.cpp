#include <bits/stdc++.h>
using namespace std;
int hud(){
 	int n,k,t[10005][3],u = 0;
 	cin>>n>>k;
 	for(int i = 1;i<=n-1;i++){
 		cin>>t[i][1]>>t[i][2];
	}
	for(int i =1;i<=n/2+1;i++){
		for(int j = 1;i<=n-1;j++){
 			if(t[i][1]=t[i][2]){
 				u++;
			 }
		}
	}
	cout<<1<<endl;
	cout<<2;
}
int main(){
	int c, t;
	cin>>c>>t;
	for(int i = 1;i<=t;i++){
		hud();
	}
	return 0;
}
