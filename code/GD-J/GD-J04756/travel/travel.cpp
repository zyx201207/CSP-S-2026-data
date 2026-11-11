#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;


int ans1,ans2,ans3,ans4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;
	if((c[0]-'0')*10 + (c[1]-'0') == (cc[0]-'0')*10 + (cc[1]-'0')){
		ans1 = 1;
	}
	if((s[0]-'0')*10 + (s[1]-'0') == (ss[0]-'0')*10 + (ss[1]-'0') && ans1 == 1){
		ans2 = 1;
	}
	if(((s[2] - 'A' <= 2 && ss[2] - 'A' <= 2) || (s[2] - 'A' > 2 && ss[2] - 'A' > 2)) && ans1 == 1 && ans2 == 1){
		ans3 = 1;
	}
	if(abs((s[2] - 'A') - (ss[2] - 'A')) == 1 && ans1 == 1 && ans2 == 1 && ans3 ==1){
		ans4 = 1;
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
