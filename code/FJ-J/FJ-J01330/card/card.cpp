#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v;
vector<int>v2;
int check(int x,int y){
	for(int i=y;i>=x;i--){
		if(v2[y]==v2[i])return i;
	}
	return -1;
}
void qk(int k){
	for(int i=k;i<=n;i++){
		v2[i]=-1;
	}
}
int main(){
	cin>>n>>m;
	int a[10000005]={0};
	v.resize(n+1,0);
	v2.resize(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		v2[j]=v[j];
		int x=check(i,j);
			if(x!=-1){
				qk(x+1);
			}
		}
		for(int i=1;i<=n;i++){
			a[v2[i]]++;
		}
	}
	for(int i=1;i<=10000000;i++){
		if(a[i]!=0){
			cout<<a[i]<<" ";
		}
	}
	return 0;
}
