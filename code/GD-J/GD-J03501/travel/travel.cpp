#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	string x1,y1;
	cin>>x>>x1>>y>>y1;
	if(x!=y){
		cout<<"0000";
		return 0;
	}cout<<1;
	if(x1[0]!=y1[0]||x1[1]!=y1[1]){
		cout<<"000";
		return 0;
	}cout<<1;
	if(!((x1[2]<='C'&&y1[2]<='C')||(x1[2]>='D'&&y1[2]>='D'))){
		cout<<"00";
		return 0;
	}cout<<1;
	if(abs(int(x1[2])-int(y1[2]))==1){
		cout<<1;
	}else{
		cout<<0;
	}return 0;
}
