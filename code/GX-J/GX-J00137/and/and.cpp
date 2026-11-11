#include<bits/stdc++.h>
using namespace std;

int a[100005];
int n,m,maxn=0;

int andnum(int t,s){
	if(t==0){
		return 1e9;
	}
	
	for(int i=s;i<t;i++){
		return a[i] & andnum(t-1,i+1);
	}
}

int main(){
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	maxn=andnum(m,0);
	
	cout<<maxn;
	
	return 0;
}
