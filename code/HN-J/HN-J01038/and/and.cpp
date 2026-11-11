#include<bits/stdc++.h>
using namespace std;
void swep1(int x,int y);
int and1(int m,int n);
int a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long b,c=0,k=1,v=0;
	cin>>b;
	for(int i=1;i<=b;i++){
		cin>>a[i]; 
		k++;
	} 
	for(int j=1;j<=k;j++){
		for(int i=1;i<=k;i++){
	        if(a[i]<a[i-1]) {
	    	swep1(a[i],a[i-1]);
		    }
	    }
	}
	cin>>c;
	v=a[1]&a[2];
	for(int i=3;i<=c;i=i+2){
		v=a[i]&a[i+1]&v;
	}
	cout<<v;
	return 0;		
}
void swep1(int x,int y){
	int q;
	q=x;
	x=y;
	y=q;
}

