//GZ-J00468 遵义市第十二中学 周泽恩 
#include<bits/stdc++.h>

using namespace std;
string c_1,c_2;
string s_1,s_2;
int ss1,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	ss1=(s_1[0]-'0')*10+(s_1[1]-'0');
	ss2=(s_2[0]-'0')*10+(s_2[1]-'0');
	if(c_1==c_2){
		cout<<1;
		if(ss1==ss2){
			cout<<1;
			if((s_1[2]=='A'||s_1[2]=='B'||s_1[2]=='C')&&(s_2[2]=='A'||s_2[2]=='B'||s_2[2]=='C')){
				cout<<1;
				if(s_1[2]+1==s_2[2]||s_1[2]-1==s_2[2]){
					cout<<1;
				}
				else{
					cout<<0;
				}
				
			}else if((s_2[2]=='D'||s_2[2]=='F')&&(s_1[2]=='D'||s_1[2]=='F')){
				cout<<1<<1;
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	fclose(stdin);
	fclose(stdout);
} 
