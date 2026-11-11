#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,ans = "1000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a != c){cout<<"0000";
	}else{
		if(b[0] == d[0] && b[1] == d[1]){
			ans[1] = '1';
			if(!((b[2] >= 'A' && b[2] <= 'C') ^ (d[2] >= 'A' && d[2] <= 'C'))){
				ans[2] = '1';
				if(abs((b[2] - 'A') - (d[2] - 'A')) == 1) ans[3] = '1';
			}
		}
		cout<<ans; 
	}
	return 0;
} 
