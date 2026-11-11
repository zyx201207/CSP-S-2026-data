#include<bits/stdc++.h>
#include<string>
#include<queue>
using namespace std;
int a[1000001],b[100001];
int q(int x){
	    for(int i=0;i<x;i++){
		if(a[x]==a[i]){
			return true;
		}	
	}
	return false;
}
int dl(int y,int x){
	for(int i=0;i<y;i++){
		y++;
		if(a[x]==a[i]){
			return y;
		}	
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,l=0,p=0,k=1,u=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		u++;
	for(int i=0+u;i<=n;i++){
		if(q(i)){
		   a[i-dl(p,i)]=a[i];		
		}
	}
	for(int i=0;i<n-dl(p,i);i++){
		for(int j=1;j<=m;j++){
		if(a[i]==j){
		   b[i]++;
		}
	}
}
	
}for(int i=0;i<m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
