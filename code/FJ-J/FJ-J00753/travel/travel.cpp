#include <iostream>
#include <cstdio> 
using namespace std;
int main(int argc, char** argv) {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string ans = "";
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int v1=(s1[0] - '0')*10+(s1[1]-'0');
	int v2=(s2[0] - '0')*10+(s2[1]-'0');
	if(c1==c2){
		if(v1==v2){
			if((s1[2] < 'D' && s2[2] < 'D') || (s1[2] > 'C' && s2[2] > 'C')){
				int d = s1[2]-s2[2];
				if(d == 1 || d == -1){
					ans = "1111";
				}else{
					ans = "1110";
				}
			}else{
				ans = "1100";
			}
		}else{
			ans = "1000";
		}
	}else{
		ans = "0000";
	}
	cout<<ans;
	return 0;
}