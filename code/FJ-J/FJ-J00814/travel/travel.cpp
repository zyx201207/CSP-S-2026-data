#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y,i=0,j=0;
	string n,m;
	cin>>x>>n>>y>>m;
	i=(n[0]-'0')*10+n[1]-'0';
	j=(m[0]-'0')*10+m[1]-'0';
	if(x!=y){
		cout<<"0000";
	}else{
		cout<<"1";
		if(i!=j){
			cout<<"000";
		}else{
			cout<<"1";
			if((n[2]<='C'&&m[2]<='C')||(n[2]>='D'&&m[2]>='D')){
				cout<<"1";
				if(abs((int)(n[2]-m[2]))==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}
	}
	return 0;
} 
