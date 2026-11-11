#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string sa,sb;
	int a,b;
	cin>>a>>sa>>b>>sb;
	int flag = 0;
	if(a == b){
		cout<<'1';
			if(sa[0] == sb[0] && sa[1] == sb[1]){
				cout<<'1';
			 	if((sa[2] == 'A'||sa[2]=='B' ||sa[2] == 'C') && (sb[2]=='A'||sb[2] == 'B'||sb[2]=='C')){
			 		cout<<'1';
			 		flag =1;
			 	}else if((sa[2] == 'D'||sa[2]=='F' ) && (sb[2]=='D'||sb[2] == 'F')){
			 	cout<<'1';
			 		flag =1;
			 	}else cout<<"00";
			}else {
				cout<<"000";
			}
	}else{
		cout<<"0000";
	}
	if(flag == 1){
		if((sa[2] == 'A' && sb[2]=='B')||(sa[2] == 'B' && sb[2]=='A')||(sa[2] == 'C' && sb[2]=='B')||(sa[2] == 'B' && sb[2]=='C')||(sa[2] == 'F' && sb[2]=='D')||(sa[2] == 'D' && sb[2]=='F')){
			cout<<'1';	
		}else cout<<'0';	
		
	}	
	
	return 0;
}
