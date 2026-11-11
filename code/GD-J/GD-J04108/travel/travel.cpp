#include<bits/stdc++.h>
#define int long long
using namespace std;

string c1,s1,c2,s2;
bool f1,f2,f3,f4;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	freopen("travel6.in","r",stdin);
//	freopen("travel6.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	f1=(c1==c2);
	f2=f1&&((s1[0]+s1[1])==(s2[0]+s2[1]));
	f3=f1&&f2&&(((s1[2]-'A')>=3&&(s2[2]-'A')>=3)||((s1[2]-'A')<=2&&(s2[2]-'A')<=2));
	f4=f1&&f2&&f3&&(abs((s1[2]-'A')-(s2[2]-'A'))==1);
	cout<<f1<<f2<<f3<<f4;
	return 0;
}//UID:930075
