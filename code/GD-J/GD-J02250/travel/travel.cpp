#include <bits/stdc++.h>
using namespace std;
string c_1;
string s_1;
string c_2;
string s_2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1;
	cin>>c_2;
	cin>>s_1;
	cin>>s_2;
	if(c_1==s_1){
		cout<<1;
		if(c_2[0]==s_2[0]&&c_2[1]==s_2[1]){
			cout<<1;
			if(c_2[2]<'D'&&s_2[2]<'D'){
				cout<<1;
				if(c_2[2]-s_2[2]==1||s_2[2]-c_2[2]==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(c_2[2]>'C'&&s_2[2]>'C'){
				cout<<1<<1;
			}else{
				cout<<0<<0;
			}
			
			
		}else{
			cout<<0<<0<<0;
		}
		
	}else{
		cout<<0<<0<<0<<0;
	}

	
	
	return 0;
	
	
	
} 
