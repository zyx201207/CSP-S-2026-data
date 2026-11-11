#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("treval.in","r",stdin);
	freopen("treval.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((char(s1[2])-'0'<=4&&char(s2[2])-'0'<=4)||(char(s1[2])-'0'>4&&char(s2[2])-'0'>4)){
				cout<<1;
				if(char(s1[2])-char(s2[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0;
			}
		}
		else{cout<<0;
		}
		
		
	}
	else{cout<<0;
	}
	
	
	
	return 0;
}
