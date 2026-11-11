#include <bits/stdc++.h>
using namespace std;
string c,s,cc,ss;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cout.tie(0);
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	cin>>c>>s>>cc>>ss;
	if(c == cc){
		if(s[0] + s[1] == ss[0] + ss[1]){
			if((s[2] <= 'C' && ss[2] <= 'C') || (s[2] >='D' && ss[2] >= 'D')){
				if(s[2] > ss[2]){
					if(s[2] - ss[2] == 1){
						cout<<"1111";
					}
					else{
						cout<<"1110";
					}	
				}
				else{
					if(ss[2] - s[2] == 1){
						cout<<"1111";
					}
					else{
						cout<<"1110";
					}
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	
	return 0;
}
