#include<bits/stdc++.h>
using namespace std;
int q=0,w[2000000];
int main(){
	int n,m;
	int a[2000000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=m;j++){
			w[i]+=a[i]&a[j];
		}
		if(w[i]>=q){
			q=w[i];
		}
	}cout<<q;
	return 0;
}
