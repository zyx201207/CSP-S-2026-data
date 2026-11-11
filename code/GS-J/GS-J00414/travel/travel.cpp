#include<bits/stdc++.h> 
using namespace std;
char c[10];
char d[10];
int a,b;
int main(){
	preopen("travel.in",'r',stdin);
	preopen("travel.out",'w',stdout);
	cin>>a>>c>>b>>d; 
	if(a==b){
		cout<<'1';
		if(c[0]==d[0]&&d[1]==c[1]){
			cout<<'1';
			if(((c[2]=='A'||c[2]=='B'||c[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((c[2]=='F'||c[2]=='F')&&(d[2]=='F'||d[2]=='D'))){
				cout<<'1';
				if(((c[2]==d[2]-1&&c[2]!='c')||(c[2]==d[2]-1&&c[2]!='c'))||((c[2]=='F'||c[2]=='F')&&(d[2]=='F'||d[2]=='D'))){
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
