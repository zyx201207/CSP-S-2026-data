#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	string ans = "0000";
	if(a == c){
		ans[0] = '1';
		int e = b[0] - '0';
		int f = b[1] - '0';
		int be = e * 10 + f;
		int g = d[0] - '0';
		int h = d[1] - '0';
		int de = g * 10 + h;
		if(be == de){
			ans[1] = '1';
			int i = b[2] - 'A';
			int j = d[2] - 'A';
			if((i >= 3 && j >= 3) || (i <= 2 && j <= 2)){
				ans[2] = '1';
				if(i <= 2;j <= 2){
					if(i - j == 1 || i - j == -1){
						ans[3] = '1';
						cout << ans;
						return 0;
					}else{
						cout << ans;
						return 0;
					}
				}
				if(i >= 3 && j >= 3){
					ans[3] = '1';
					cout << ans;
					return 0;
				}
			}else{
				cout << ans;
				return 0;
			}	
		}else{
			cout << ans;
			return 0;
		}	
	}else{
		cout << ans;
		return 0;
	}
	return 0;
} 
