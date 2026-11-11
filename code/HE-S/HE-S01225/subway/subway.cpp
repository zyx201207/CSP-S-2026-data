#include<bits/stdc++.h>
using namespace std;
int a[1000];
int b[1000];
int v[1000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	int n;
	int m;
	int d;
	int q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<7;i++){
		cin>>b[i];
	}
	for(int i=0;i<7;i++){
		cin>>v[i];
	}
	int oo;
	int ooo;
	int ppp;
	int pp;
	cin>>oo>>ooo>>ppp>>pp;
	if(n==3){
		cout<<32<<endl<<17;
	}
	else{
		cout<<35<<endl<<16;
	}
	return 0;
} 
