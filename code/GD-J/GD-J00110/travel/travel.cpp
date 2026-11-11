#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string firsta,firstb,seconda,secondb;
	cin>>firsta>>firstb>>seconda>>secondb;
	if(firsta!=seconda){
		cout<<"0000";
		return 0;
	}else{
		for(long long i=0;i<2;i++){
			if(firstb[i]!=secondb[i]){
				cout<<"1000";
				return 0;
			}
		}
		char a=firstb[2],b=secondb[2];
		if(a<='C'&&b<='C'){
			if(abs(a-b)==1){
				cout<<"1111";
				return 0;
			}else{
				cout<<"1110";
				return 0;
			}
		}else if(a>'C'&&a<='F'&&b>'C'&&b<='F'){
			cout<<"1111";
			return 0;
		}else{
			cout<<"1100";
			return 0;
		}
	}
	return 0;
}
