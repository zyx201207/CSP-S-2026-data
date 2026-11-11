#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char cr,cx;
bool flagr,flagx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>b>>cr>>c>>d>>cx;
	if(cr=='D'||cr=='F'){
		flagr=true;
	}
	else{
		flagr=false;
	}
	if(cx=='D'||cx=='F'){
		flagx=true;
	}
	else{
		flagx=false;
	}
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if(flagr==flagx){
				cout<<1;
				if(flagr){
					cout<<1;
				}
				else if((cr=='A'&&cx=='C')||(cr=='C'&&cx=='A')){
					cout<<0;
				}
				else{
					cout<<1;
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
