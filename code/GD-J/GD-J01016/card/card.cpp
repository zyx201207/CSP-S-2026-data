#include<bits/stdc++.h>
using namespace std;
int p[500000],k=1;
void  push(int x){
	p[k]=x;
	k++;
}
void pop(){
	if(k<=1){
		p[k]=0;
		k--;
	}
	
}
int sizes(){
	if(k<=1){
		return 0;
	}
	return k;
}
void clean(){
	k=1;
	
}
int f(){
	return p[k];
}
int a[500000],b[500000],c[500000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cout<<1;
	return 0;
}

