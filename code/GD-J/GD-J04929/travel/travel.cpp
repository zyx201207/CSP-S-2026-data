#include <bits/stdc++.h>
using namespace std;
int che1,che2;
char che_1[4],che_2[4];
char ans[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>che1>>che_1>>che2>>che_2;
	if(che1==che2){
		char s1[3];
		s1[0]=che_1[0];
		s1[1]=che_1[1];
		char s2[3];
		s2[0]=che_2[0];
		s2[1]=che_2[1];
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			char s3=che_1[2];
			char s4=che_2[2];
			if((s3=='A'&&s4=='B')||(s3=='A'&&s4=='C')||(s3=='B'&&s4=='A')||(s3=='B'&&s4=='C')||(s3=='C'&&s4=='A')||(s3=='C'&&s4=='B')||(s3=='D'&&s4=='F')||(s3=='F'&&s4=='D')){
				if((s3=='A'&&s4=='B')||(s3=='B'&&s4=='C')||(s3=='B'&&s4=='A')||(s3=='C'&&s4=='B')||(s3=='F'&&s4=='D')||(s3=='D'&&s4=='F')){
					ans[0]='1';
					ans[1]='1';
					ans[2]='1';
					ans[3]='1';					
				}
				else {
					ans[0]='1';
					ans[1]='1';
					ans[2]='1';
					ans[3]='0';
				}
			}
			else{
				ans[0]='1';		
				ans[1]='1';	
				ans[2]='0';	
				ans[3]='0';			
			}
		}
		else{
			ans[0]='1';	
			ans[1]='0';	
			ans[2]='0';	
			ans[3]='0';	
		}
	}
	else{
		ans[0]='0';	
		ans[1]='0';	
		ans[2]='0';	
		ans[3]='0';	
	}
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
	return 0;
}
