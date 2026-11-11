#include<bits/stdc++.h>
using namespace std;

string ans[6];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2){
		ans[1]='0';
		ans[2]='0';
		ans[3]='0';
		ans[4]='0';
	}else{
		ans[1]='1';
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			ans[2] = '1';
			if(s1[2]<='C' && s2[2]<='C'){
				ans[3] = '1';
					
				if(s1[2]=='B' || s2[2]=='B'){
				ans[4] = '1';			
				}
						
				}
			
			
			if(s1[2]>'C' && s2[2]>'C'){
				ans[3] = '1';
				ans[4] = '1';
			}
		}
	}
	
	for(int i=1;i<=4;i++){
		if(ans[i]=="1"){
			cout << ans[i];
		}
		else cout << '0';
	}
	
	return 0; 
}
