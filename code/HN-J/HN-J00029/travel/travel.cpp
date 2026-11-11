#include<bits/stdc++.h>
using namespace std;
int a,b,c[11]={1,1,1,2,2};
string r,l;
int zhuan(char x){
	if(x=='A'){
		return 0;
	}
	if(x=='B'){
		return 1;
	}
	if(x=='C'){
		return 2;
	}
	if(x=='D'){
		return 3;
	}
	if(x=='F'){
		return 4;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>r>>b>>l;
	if(a==b){
		cout<<"1";
		if(r[0]==l[0]&&r[1]==l[1]){
			cout<<"1";
			int x,y;
			x=zhuan(r[2]);
			y=zhuan(l[2]);
			if(c[x]==c[y]){
				cout<<"1";
				if(abs(x-y)==1&&(!((x==2&&y==3)||(x==3&&y==2)))){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
