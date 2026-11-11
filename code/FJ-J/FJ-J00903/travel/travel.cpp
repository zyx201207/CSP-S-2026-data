#include<bits/stdc++.h> 
using namespace std;
string ca,sa,cb,sb,ans = "0000";
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> ca >> sa >> cb >> sb;
	if(ca == cb){
		ans[0] = '1';
		if(sa[0] == sb[0] && sa[1] == sb[1]){
			ans[1] = '1';
			if((sa[2] >= 'A' && sa[2] <= 'C' && sb[2] >= 'A' && sb[2] <= 'C') || ((sa[2] == 'D' && sb[2] == 'F') || (sa[2] == 'F' && sb[2] == 'D'))){
				ans[2] = '1';
				if((sa[2] == 'A' && sb[2] == 'B') || (sa[2] == 'B' && sb[2] == 'A') || (sa[2] == 'B' && sb[2] == 'C') || (sa[2] == 'C' && sb[2] == 'B') || (sa[2] == 'D' && sb[2] == 'F') || (sa[2] == 'F' && sb[2] == 'D')){
					ans[3] = '1';
				}
			}
		}
	}
	cout << ans;
	return 0;
}
