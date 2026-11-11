#include <bits/stdc++.h>
using namespace std;
string cA,sA,cB,sB;
int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel5.out","w",stdout);
	cin>>cA>>sA>>cB>>sB;
	if(cA==cB){
		cout<<1;
		if(sA[0]==sB[0] and sA[1]==sB[1]){
			cout<<'1';
			if((sA[2]-'A'<=2 and sB[2]-'A'<=2)){
				cout<<'1';
				if(abs(sA[2]-sB[2])==1){
					cout<<'1';
					return 0;
				}else{
					cout<<'0';
					return 0;
				}
			}else if((sA[2]=='F' and sB[2]=='D') or (sA[2]=='D' and sB[2]=='F')){
				cout<<"11";
				return 0;
			}
			else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
