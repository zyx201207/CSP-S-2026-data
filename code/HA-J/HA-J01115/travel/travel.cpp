#include<bits/stdc++.h> 
using namespace std;
int x,y;
char b[2][100];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>b[0]>>y>>b[1];
	if(x!=y){
		cout<<"0000"<<endl;
	}else {
		x=(b[0][0]-'0')*10+b[0][1]-'0';
		y=(b[1][0]-'0')*10+b[1][1]-'0';
		cout<<1;
		if(x!=y){
			cout<<"000"<<endl;
		}else{
			x=b[0][2]-'A';
			y=b[1][2]-'A';
			cout<<1;
			if((x<3&&y<3)||(x>2&&y>2)){
				cout<<1;
				x-=y;
				if(x==1||x==-1)cout<<1;
				else cout<<0;
			}else {
				cout<<"00";
			}
		}
	}
	return 0;
}
