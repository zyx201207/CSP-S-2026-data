#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x1,x2,y1,y2;
	char c1,c2;
	cin>>x1>>x2>>c1>>y1>>y2>>c2;
//	cout<<x1<<x2<<c1<<y1<<y2<<c2;
	if(x1==y1){
		cout<<"1"; 
		if(x2==y2){
			cout<<"1";
			if((c1<='C' && c2<='C') || (c1>='D' && c2>='D')){
				cout<<"1";
				if(abs((int)c1-c2)==1){
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
