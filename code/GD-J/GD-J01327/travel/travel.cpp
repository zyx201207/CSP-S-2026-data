#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x[3],y[3];
	cin>>x[0]>>x[1]>>y[0]>>y[1];
	if(x[0]!=y[0]){
		cout<<"0000"<<endl;
	}else if(x[1][0]!=y[1][0]||x[1][1]!=y[1][1]){
		cout<<"1000"<<endl;
	}else if((x[1][2]=='F'&&y[1][2]!='D')||
	(x[1][2]=='D'&&y[1][2]!='F')||
	(y[1][2]=='F'&&x[1][2]!='D')||
	(y[1][2]=='D'&&x[1][2]!='F')){
		cout<<"1100"<<endl;
	}else if(max(int(x[1][2]),int(y[1][2]))-min(int(x[1][2]),int(y[1][2]))!=1){
		cout<<"1110"<<endl;
	}else{
		cout<<"1111"<<endl;
	}
	return 0;
} 
