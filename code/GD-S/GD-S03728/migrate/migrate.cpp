#include<bits/stdc++.h>
using namespace std;
const int M=2e6;
int x[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int q;
		q=x[n]-x[1];
		cout<<q/d<<'\n';
	}
	return 0;
} 
