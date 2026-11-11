#include<bits/stdc++.h>
#include<string>
using namespace std;
string c1,s1,c2,s2;
string ans = " ";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1>>s1>>c2>>s2;
	if(c1 == c2){
		ans = "1000";
		if(s1[1]!=s2[1]){
			cout << ans;
			return 0;
		}
		else{
			ans = "1100";
			if(abs(s1[2]-s2[2])<=2){
				if(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C'){
					cout <<ans;
					return 0;
				}
				ans = "1110";
				if(abs(s1[2]-s2[2])==1){
					cout << "1111";
				}else{
					cout << ans;
				}
			}
			else{
				cout<<ans; 
			}
		}
	}
	else{
		cout << "0000";
	}
	return 0;
}
