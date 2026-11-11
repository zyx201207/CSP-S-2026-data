#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int a,b,c,d;
	cin>>a>>b>>c>>d;	
	if(!a-b==1){
		cout<<"0000";return 1;
	}else  cout<<"1";
	if(d-c==0){
	cout<<"1";
	}else cout<<"0";
	if(c-d>0){
		cout <<"1";
			}else cout<<"0";
			if(c-d<0){
				cout<<"1";
			}else cout<<"0";
		
	return 0;
	
	
}
