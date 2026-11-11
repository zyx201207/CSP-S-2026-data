#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2; 
int x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x=(s1[0]-'0')*10+s1[1]-'0';
	y=(s1[0]-'0')*10+s2[1]-'0';
	if(c1==c2){
		cout<<1;
		//cout<<' '<<s1[2]-s2[2]<<endl;
		if(x==y){
			cout<<1;
			if(s1[2]=='A'&&(s2[2]!='D'&&s2[2]!='F')){
				cout<<1;
				if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
					cout<<1;
					//cout<<endl<<1;
				}else{
					cout<<0;
				}
			}else if(s1[2]=='B'&&(s2[2]!='D'&&s2[2]!='F')){
				cout<<1;
				if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
					cout<<1;
				//	cout<<endl<<2;
				}else{
					cout<<0;
				}
			}else if(s1[2]=='C'&&(s2[2]!='D'&&s2[2]!='F')){
				cout<<1;
				if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
					cout<<1;
					//cout<<endl<<3;
				}else{
					cout<<0;
				}
				//cout<<endl<<s1[2]-s2[2];
			}else if(s1[2]=='D'&&s2[2]=='F'){
				cout<<11;
				//cout<<endl<<4;
			}else if(s1[2]=='F'&&s2[2]=='D'){
				//cout<<endl<<15;
				cout<<11;
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
