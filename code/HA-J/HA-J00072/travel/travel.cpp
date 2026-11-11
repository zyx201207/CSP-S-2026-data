#include<bits/stdc++.h>
using namespace std;
int num(string s){
	int ans=0;
	for(int i=0;i<s.size();i++){
		ans =ans*10+s[i]-'0';
	}
	return ans;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<'1';
		string ax,bx;
		char ay,by;
		ax = b[0]+b[1];
		ay = b[2];
		bx = d[0]+d[1];
		by= d[2];
		int nx,ny;
		nx = num(ax);
		ny = num(bx);
		if(ax==bx){
			cout<<'1';
			if(ay>='D'&&by>='D'||ay<'D'&&by<'D'){
				cout<<'1';
					if(nx==ny){
						if(ay==by+1||ay==by-1){
							cout<<'1';
						}
						else{
							cout<<'0';
						}
					}
					else if(ay==by){
						if(nx==ny+1||nx==ny-1){
							cout<<'1';
						}
						else{
							cout<<'0';
						}				
					}
					else{
						cout<<'0';
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
