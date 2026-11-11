#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,b;
	string x,y;
	cin>>a>>x>>b>>y;
	if(a==b){
		if(x[0]==y[0]&&x[1]==y[1]){
			if(((x[2]-'A')>=3&&(y[2]-'A')>=3)||((x[2]-'A')<3&&(y[2]-'A')<3)){
				if(x[2]-y[2]==1||y[2]-x[2]==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
		
	}else{
		cout<<"0000";
		
	}
	return 0;
}
