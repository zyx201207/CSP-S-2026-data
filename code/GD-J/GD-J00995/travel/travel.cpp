#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	string ans;
	cin >> a >> b >> c >> d;
	if(b[2]=='F')b[2] = 'E';
	if(d[2]=='F')b[2] = 'E';
	if(a==c)ans+='1';
	else{
		ans = "0000";
		cout << ans;
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1])ans+='1';
	else ans+='0';
	if(b[0]==d[0]&&b[1]==d[1]&&(('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C')||('D'<=b[2]&&b[2]<='F'&&'D'<=d[2]&&d[2]<='F')))ans+='1';
	else ans+='0';
	if(ans[2]=='1'){
		if(abs(b[2]-d[2])==1)ans+='1';
		else ans+='0';
	}
	else ans+='0';
	cout << ans;
	return 0;
}
