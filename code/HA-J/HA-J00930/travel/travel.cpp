#include<bits/stdc++.h>
using namespace std;
long long c1,s1,c2,s2;
char s1_1,s2_1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>s1_1>>c2>>s2_1>>s2;
	if(c1!=01&&c1!=16&&c2!=01&&c2!=16){
		if(c1==c2){
			cout<<"1";
		}else{
			cout<<"0";
		}if(s1==s2){
			cout<<"1";
		}else{
			cout<<"0";
		}if((s1_1>='D'&&s2_1>='D')||(s1_1<='C'&&s2_1<='C')){
			cout<<"1";
		}else{
			cout<<"0";
		}if(s1_1<='C'&&s2_1<='C'){//||(s1_1=='B'&&s2_1=='B')||(s1_1=='A'&&s2_1=='A')
			if(s1_1-s2_1=='1'||s2_1+s1_1=='1'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
	}
	return 0;
}
