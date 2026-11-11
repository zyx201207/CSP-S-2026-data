#include<bits/stdc++.h> 
using namespace std;
struct zw{
	int cxh;
	string zwh;
}; 
zw a[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<2;i++){
		cin>>a[i].cxh>>a[i].zwh;
	}
	if(a[0].cxh==a[1].cxh){
		cout<<1;
		if(a[0].zwh[0]==a[1].zwh[0]&&a[0].zwh[1]==a[1].zwh[1]){
			cout<<1;
			if(a[0].zwh[2]+1==a[1].zwh[2]||a[0].zwh[2]-1==a[1].zwh[2]){
				if(a[0].zwh[2]=='C'&&a[1].zwh[2]=='D'){
					cout<<"00";
				}
				else cout<<11; 
			}else cout<<"10";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
