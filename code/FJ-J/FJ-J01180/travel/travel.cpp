#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ca,cb;
	string za,zb;
	cin>>ca>>za>>cb>>zb;
	if(ca==cb){
		cout<<'1';
		if(za[0]==zb[0]&&za[1]==zb[1]){
			cout<<'1';
			if((za[2]<='C'&&zb[2]<='C')||(za[2]>='D'&&zb[2]>='D')){
				cout<<'1';
				int pa=int(za[2]);
				int pb=int(zb[2]);
				if(pa>pb){
					swap(pa,pb);
				}
				if(pa+1==pb){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
}
