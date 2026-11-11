#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	
	string c_1,c_2,s_1,s_2;
	cin>>c_1>>s_1>>c_2>>s_2;
	
	if(c_1 == c_2){
		cout<<"1";
		
		int cnt = 0;
		for(int i=0;i<2;i++){
			if(s_1[i] == s_2[i]){
				cnt++;
			}
		}
		if(cnt == 2){
			cout<<"1";
			
			if((s_1[2] == 'D' && s_2[2] == 'E') || (s_1[2] == 'E' && s_2[2] == 'D') || ((s_1[2] == 'A'||s_1[2] == 'B'||s_1[2] == 'C') && (s_2[2] == 'A'||s_2[2] == 'B'||s_2[2] == 'C'))){
				cout<<"1";
				
				if(s_1[2] == 'D'&&s_2[2] == 'E'){
					cout<<"1";
				}
				else if(s_1[2] == 'E'&&s_2[2] == 'D'){
					cout<<"1";
				}
				else if((s_1[2] == 'A' && s_2[2] == 'B') || (s_1[2] == 'B' && s_2[2] == 'A')){
					cout<<"1";
				}
				else if((s_1[2] == 'B' && s_2[2] == 'C') || (s_1[2] == 'C' && s_2[2] == 'B')){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else {
		cout<<"0000";
	}
	
	return 0;
} 
