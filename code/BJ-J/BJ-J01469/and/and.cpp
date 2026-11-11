#include<bits/stdc++.h>
using namespace std;
long long y[200100]={0};
int xp,xe;
int ands(int t,int m){
	return t&m;
}
int main(){
    int a,b;
    cin>>a>>b;
    for(int p=0;p<a;p++){
		cin>>y[p];
	}
	int maxs=0,maxpp;
	for(int yp=0;yp<b-1;yp++){
		if(maxs==0){
		for(int p=0;p<a;p++){
		for(int e=p+1;e<a;e++){
		maxs=max(maxs,ands(y[p],y[e]));
		xp=p;
		xe=e;
	}
	}
	y[xp]=0;
	y[xe]=0;
	maxpp=maxs;
}else{
	for(int l=0;l<a;l++){
		maxs=max(maxs,ands(maxpp,y[l]));
	}
}
	
	}
	cout<<maxs;
	return 0;
}
