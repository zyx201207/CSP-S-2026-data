#include<bits/stdc++.h>
#define long long int
using namespace std;

bool cs0=0;

int cs(int cs1,string s){
	if(cs0==1){
		cout<<s<<":"<<cs1<<endl;
	}
	return cs1;
}
//±äÁ¿
int a,b;
int x_num,y_num;
string s11,s22;
signed main(){
	if(cs0==0){
	ios::sync_with_stdio(0);
		cin.tie(0); 
		freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
		
	}
	
	//´úÂë 
	cin>>a>>s11>>b>>s22;
	x_num=(s11[0]-'0')*10+(s11[1]-'0');
	y_num=(s22[0]-'0')*10+(s22[1]-'0');
	cs(x_num,"x");
	cs(y_num,"y");
	if(a==b){
		cout<<"1";
		if(x_num==y_num){
			cout<<"1";
			if(s11[2]<='C'&&s11[2]>='A'&&s22[2]<='C'&&s22[2]>='A'){
				cout<<"1";
				if(abs(s11[2]-s22[2])==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if(s11[2]<='E'&&s11[2]>='D'&&s22[2]<='E'&&s22[2]>='D'){
				cout<<"11";
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
