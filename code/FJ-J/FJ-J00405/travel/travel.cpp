#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		string temp1="",temp2="";
		temp1+=b[0]+b[1];
		temp2+=d[0]+d[1];
		if(temp1==temp2){
			cout<<"1";
			char r=b[2],c=d[2];
			if(r=='A'||r=='B'||r=='C'){
				r='L';
			}
			else{
				r='R';
			}
			if(c=='A'||c=='B'||c=='C'){
				c='L';
			}
			else{
				c='R';
			}
			if(c!=r){
				cout<<"00";
			}
			else{
				cout<<"1";
				int ridx,cidx;
				r=b[2],c=d[2];
				if(r=='A'){
					ridx=1;
				}
				else if(r=='B'){
					ridx=2;
				}
				else{
					ridx=3;
				}
				if(c=='A'){
					cidx=1;
				}
				else if(c=='B'){
					cidx=2;
				}
				else{
					cidx=3;
				}
				//cout<<cidx<<" "<<ridx;
				if(abs(ridx-cidx)==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
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
