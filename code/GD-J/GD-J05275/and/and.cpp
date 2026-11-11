#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[200005],n,m,b[40],c=33,g=1,d[200005],e=0,bb[40]; 
bool l[200005][38];
int an(int x){
	if(x==-1)return 0;
	int d=0;
	for(int i=0;i<n;i++){
	if((l[i][x]==1)&&(x+l[i][32]==c)){
	l[i][32]++;
	d++;
	cout<<2;
	}}
	if(d>m){
		int j=1;
		for(int i=0;i<x+1;j*=2);
		e+=j;
	}
	x--;
	an(x);
	return 0;
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0,d;i<n;i++){
	cin>>d;
	for(int j=-1;0<d;d/=2){
	l[i][++j]=d%2;
	if(d%2==1)b[j]++;	
	}
	}
	for(;b[c]<m;c--);
	an(--c);
	cout<<e;
	return 0;
}
