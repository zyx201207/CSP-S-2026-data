#include<bits/stdc++.h>
using namespace std;

string cr,ir,cx,ix;
int a=1,b=1,c=1;
int t[5]={1,1,1,0,0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>ir>>cx>>ix;
	
	for(int i=0;i<cr.size();i++){
		if(cr[i]!=cx[i]){
			a=0;
			break;
		}
	}
	if(a==0){
		cout<<"0000";
		return 0;
	}else cout<<1;
	for(int i=0;i<ir.size()-1;i++){
		if(ir[i]!=ix[i]){
			b=0;
			break;
		}
	}
	if(b==0){
		cout<<"000";
		return 0;
	}else cout<<1;
	int x=ir[2]-'A',y=ix[2]-'A';
	if(t[x]!=t[y]){
		cout<<"00";
		return 0;
	}else cout<<1;
	if(x-y==1 || y-x==1){
		cout<<1;
	}else cout<<0;
	return 0;
}
