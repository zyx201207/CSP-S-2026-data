#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	string ans = "";
	if(a==c){
		ans += "1";
		if(b[0]==d[0]&&b[1]==d[1]){
			ans += "1";
			bool flag = false;
			if(b[2]>d[2])
				swap(b,d);
			if(b[2]=='A'&&d[2]=='B')
				flag = true;
			else if(b[2]=='A'&&d[2]=='C')
				flag = true;
			else if(b[2]=='B'&&d[2]=='C')
				flag = true;
			else if(b[2]=='D'&&d[2]=='E')
				flag = true;
			if(flag){
				ans += "1";
				if(b[2]+1==d[2]&&b[2]!='C')
					ans += "1";
				else
					ans += "0";
			}
			else{
				ans += "00";
			}
		}
		else{
			ans += "000"; 
		}
	}
	else{
		ans = "0000";
	}
	cout << ans;
	return 0;
} 
