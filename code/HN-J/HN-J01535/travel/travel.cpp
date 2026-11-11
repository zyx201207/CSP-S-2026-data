#include<bits/stdc++.h> 
using namespace std;

struct ling{
	string che,zuo;
}ling1,ling2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int t;
	cin>>ling1.che>>ling1.zuo;
	cin>>ling2.che>>ling2.zuo;
	///////
	if(ling1.che==ling2.che&&ling1.che[1]!=1&&ling1.che[1]!=16){
		cout<<'1';
	}else{
		cout<<'0';
	}
	/////////
	if(ling1.zuo[0]==ling2.zuo[0]&&ling1.zuo[1]==ling2.zuo[1]){
		cout<<'1';
		if(ling1.zuo[2]>='A'&&ling1.zuo[2]<='C'){
			if(ling2.zuo[2]>='A'&&ling2.zuo[2]<='C'){
				t=1;
				cout<<'1';
			}else{
				t=0;
				cout<<'0';
			}
		}else {
			if(ling2.zuo[2]>='D'&&ling2.zuo[2]<='E'){
				t=1;
				cout<<'1';
			}else {
				t=0;
				cout<<'0';
			}
		}
	}else{
		cout<<"00";
	}
	//////////
	if((ling1.zuo[2]-ling2.zuo[2]==1||ling1.zuo[2]-ling2.zuo[2]==-1)&&t==1){
		cout<<'1';
	}else cout<<'0';
	return 0;
}
