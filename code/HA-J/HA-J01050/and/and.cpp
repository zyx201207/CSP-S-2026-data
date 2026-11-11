#include <bits/stdc++.h>
using namespace std;


int main(int argc, char** argv) {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a,x=0,y=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a>x){
			y=x;
			x=a;
			
		}
		if(a>y&&y<x&&a<x){
			
			y=a;
		}
	}cout<<y;
	return 0;
}
