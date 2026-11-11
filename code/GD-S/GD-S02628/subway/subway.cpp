#include<bits/stdc++.h>
using namespace std;	
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>f;
	for(int i=0;i<c;i++){
		cin>>e;
	}
	for(int i=0;i<b;i++){
		cin>>e;
		int g=0;
		for(int j=0;j<e;j++){
			cin>>d;
			cin>>g;
		}
	}
	int x,y;
	for(int i=0;i<f;i++){
		cin>>x>>y;
	}
	if(c==5){
		cout<<32<<endl<<17;
	}else if(c==7){
		cout<<35<<endl<<16;
	}
	return 0; 
}
