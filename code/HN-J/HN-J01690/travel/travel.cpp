#include<bits/stdc++.h>
using namespace std;
string c1 , s1 , c2 , s2;
int a , b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c1>>s1>>c2>>s2;
	if(c1.size() != c2.size()){
		cout<<"0000";
	}
	else {
		for(int i = 0 ; i < c1.size() ; i++ ){
			a = a*10+c1[i]-'0';
			b = b*10+c2[i]-'0';
		}
		if(a != b){
			cout<<"0000";
		}
		else {
			cout<<"1";
			a = 0 , b = 0;
			if(s1.size() != s2.size()){
				cout<<"000";
			}
			else {
				for(int i = 0 ; i < s1.size()-1 ; i++ ){
					a = a*10+s1[i]-'0';
					b = b*10+s2[i]-'0';
				}
				if(a == b){
					cout<<"1";
					a = 0 , b = 0;
					for(int i = s1.size()-2 ; i < s1.size() ; i++){
						a = s1[i]-'0';
						b = s2[i]-'0';
					}
					if(a <= 19 and b <= 19){
						cout<<"1";
						if(abs(a-b) == 1) cout<<"1";
						else cout<<"0";
					}
					else if((a == 20 or a == 21) and (b == 20 or b == 21)){
						cout<<"11";
					}
					else if((a <= 19 and (b ==20 or b == 21)) or(b <= 19 and (a ==20 or a == 21))) cout<<"00";
				}
				else {
					cout<<"000";
				}
			}
		}
	}
	return 0;
}
