#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	int a,b;
	string ai,bi;
	cin>>a>>ai>>b>>bi;
	if(a==b){
		cout<<"1";
	if(ai[0]==bi[0]&&ai[1]==bi[1]){
		cout<<"1";
		if(ai[2]!='F'&&ai[2]!='D'&&bi[2]!='F'&&bi[2]!='D'){
			cout<<"1";
			if(abs(ai[2]-bi[2])==1){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else if((ai[2]=='F'||ai[2]=='D')&&(bi[2]=='F'||bi[2]=='D')){
			cout<<"1";
			if(abs(ai[2]-bi[2])==1){
				cout<<"1";
			}else{
				cout<<"0";
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
