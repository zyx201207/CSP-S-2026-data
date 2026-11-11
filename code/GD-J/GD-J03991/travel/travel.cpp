#include<bits/stdc++.h>
using namespace std;
int c,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1; 
	cin>>c>>c1>>s>>s1;
	if(c==s){
		cout<<1;
		if(c1[0]==s1[0]&&c1[1]==s1[1]){
			cout<<1;
			if((c1[2]=='F'&&s1[2]=='D')||(c1[2]=='D'&&s1[2]=='F')||(s1[2]!='D'&&s1[2]!='F'&&c1[2]!='F'&&c1[2]!='D')){
				cout<<1;
				if(c1[2]<='C'){
					if(c1[2]-1==s1[2]||s1[2]-1==c1[2]){
						cout<<1<<endl;
					}else cout<<0<<endl;
					
				}else if(c1[2]>'C'&&s1[2]>'C') cout<<1<<endl;
				else cout<<0<<endl;			
			}else cout<<"00"<<endl;
		}else cout<<"000"<<endl;	
	}else cout<<"0000"<<endl; 
	
	return 0;
} 
