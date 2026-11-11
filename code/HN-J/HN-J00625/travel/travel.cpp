#include <bits/stdc++.h>
using namespace std;
string a,b,x,y;
int yzy(char x,char y){
	if (x+y=='F'+'D'){
		return 1;
	}else if(x=='B'||y=='B'){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if (a==b){
		cout<<"1";
		if (x[0]==y[0]&&x[1]==y[1]){
			cout<<"1";
			if ((x[2]+y[2]=='F'+'D')||(x[2]<'D'&&y[2]<'D')){
				cout<<"1";
				cout<<yzy(x[2],y[2]);
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
