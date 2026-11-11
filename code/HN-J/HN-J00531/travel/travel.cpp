#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int  a,b,c,d;
	char x,y;
	cin>>a>>b>>x>>c>>d>>y;
	if(a==c){
		if(d==b){
			if(int(x-'A'+1>=4&&y-'A'+1>=4||x-'A'+1<=3&&y-'A'+1<=3)){
				if(char(x+1)==y||char(y+1)==x){
					cout<<1111;
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
