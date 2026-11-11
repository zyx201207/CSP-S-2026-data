//GZ-J00206 杨俊毅 遵义市南白初级中学 
#include<bits/stdc++.h>
using namespace std;
bool q1=0,q2=0,q3=0;
string c1,c2,c3,c4;
int main(){
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3){
    	cout<<1;
    	q1=1;
	}else{
		cout<<0;
	}
	if(q1&&c2[1]==c4[1]&&c2[0]==c4[0]){
		cout<<1;
		q2=1;
	}else{
		cout<<0;
	}
	if(q1&&q2){
		 if(c2[2]=='A'&&(c4[2]=='B'||c4[2]=='C')){
			q3=1;
			cout<<1;
		}
		else if(c2[2]=='B'&&(c4[2]=='A'||c4[2]=='C')){
			q3=1;
			cout<<1;
		}
		else if(c2[2]=='C'&&(c4[2]=='A'||c4[2]=='B')){
			q3=1;
			cout<<1;
		}
		else if(c2[2]=='E'&&c4[2]=='F'){
			q3=1;
			cout<<1;
		}
		else if(c2[2]=='F'&&c4[2]=='E'){
			q3=1;
			cout<<1;
		}else{
			cout<<0;
		}
	}else cout<<0;
	if(q1&&q2&&q3){
		if(c2[2]>c4[2]){
			if(c2[2]!='D'&&c4[2]!='C'&&c2[2]-c4[2]==1){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(c2[2]<c4[2]){
			if(c2[2]!='C'&&c4[2]!='D'&&c4[2]-c2[2]==1){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else{
	cout<<0;
}
	return 0;
}

