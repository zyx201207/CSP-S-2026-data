#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;
	if (c==cc){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if (s[0]==ss[0]&&s[1]==ss[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}

	bool ok=0;
	if (((s[2]-'A'+1<=3)&&(ss[2]-'A'+1<=3))||((s[2]-'A'+1>3)&&(ss[2]-'A'+1>3))){
		cout<<1;
		ok=1;
	}
	else{
		cout<<0;
	}
	if (abs((ss[2]-'A'+1)-(s[2]-'A'+1))==1){
		if (ok==1)
			cout<<1;
		else
			cout<<0;
	}
	else{
		cout<<0;
	}
	return 0;
}
