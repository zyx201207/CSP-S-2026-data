#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c1,c3;
	string c2,c4;
	
	cin>>c1>>c2>>c3>>c4;
	
	if(c1==c3){
		if(c2[0]==c4[0]&&c2[1]==c4[1]){
			int i2=c2[2]-'A',i4=c4[2]-'A';
			if((i2<=2&&i4<=2)||(i2>2&&i4>2)){
				if(abs(i2-i4)==1){
					cout<<"1111";
					return 0;
				}else{
					cout<<"1110";
					return 0;
				}
			}else{
				cout<<"1100";
				return 0;
			}
		}else{
			cout<<"1000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	
	return 0;
}
