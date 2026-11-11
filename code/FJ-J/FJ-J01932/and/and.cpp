#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int c[a];
    for(int i=1;i<=a;i++){
    	cin>>c[i];
	}
	int g=0;
	int jg=0;
	for(int i=1;i<=a;i++){
		for(int k=i;k<=a-b+1;k++){
			g=c[i];
		for(int j=1;j<b;j++){
			g=g&c[k+j];
		}
		if(g>jg){
			jg=g;
		}
	}
	}
	cout<<jg;
	return 0;
}
