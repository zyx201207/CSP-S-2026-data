#include<bits/stdc++.h>
using namespace std;
int a[500001],b[500001][500001];
int f(int x,int y,int z){
	for(int i=1;i<=y;i++){
		if(b[x][i]==z) return i-1;
	}
	return -1;
}
int del(int x,int y,int z){
	for(int i=x;i<=z-1;i++) b[y][i]=0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cout<<1;
			if(f(i,j,a[j])==-1) b[i][j]=a[j];
			else del(f(i,j,a[j]),i,j);
		}
	}
	int s=0;
	for(int i=1;i<=m;i++){
		s=0;
		for(int j=1;j<=n;j++){
			if(f(j,500000,i)!=-1) s++;
		}
		cout<<s<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
