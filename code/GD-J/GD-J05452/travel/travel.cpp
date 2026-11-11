#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,x2,y,y2;
	cin>>x>>x2>>y>>y2;
	if(x==y){
		cout<<"1";
		string x3,y3;
		for(int i=0;i<2;++i){
			x3+=x2[i];
			y3+=y2[i];
		}
		if(x3==y3){
			cout<<"1";
			char x4=x2[x2.size()-1],y4=y2[y2.size()-1];
			if((x4<'D'&&y4<'D')||(x4>'C'&&y4>'C')){
				cout<<"1";
				if(fabs(x4-y4)==1||(x4>'C'&&y4>'C'))cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
}
