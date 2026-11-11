#include<bits/stdc++.h>
using namespace std;
bool check(string x,string y){
	for(int i=0;i<2;i++){
		if(x[i]!=y[i]){
			return false;
		}
	}
	return true;
}
bool check1(string x,string y){
	if('A'<=x[2]&&x[2]<='C'){
		if('A'<=y[2]&&y[2]<='C'){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		if('A'<=y[2]&&y[2]<='C'){
			return false;
		}
		else{
			return true;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	string x,y;
	string xt,yt;
	cin>>x>>xt>>y>>yt;
	if(!check(x,y))cout<<"0000"<<endl;
	else{
		cout<<1;
		if(!check(xt,yt))cout<<"000"<<endl;
		else{
			cout<<1;
			if(!check1(xt,yt))cout<<"00"<<endl;
			else{
				cout<<1;
				char xx=xt[2],yy=yt[2];
//				cout<<xx<<' '<<yy<<endl; 
				if(xx=='D'||xx=='F')cout<<1<<endl;
				else{
//					cout<<2;
					if(xx=='A'&&yy=='B'||xx=='B'&&(yy=='C'||yy=='A')||xx=='C'&&yy=='B'){
						cout<<1<<endl;
					}
					else{
						cout<<0<<endl;
					}
				}
			}
		}
	}
	return 0; 
} 

