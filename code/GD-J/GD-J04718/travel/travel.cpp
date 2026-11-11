#include<bits/stdc++.h>
#define int ll
#define inf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
typedef long long ll;
using namespace std;
const int N=1000010;

const int t[]={1,2,3,1001,1001,1002};
string c1,c2,s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"1000";
	else if(abs(t[s1[2]-'A']-t[s2[2]-'A'])>100)cout<<"1100";
	else if(abs(t[s1[2]-'A']-t[s2[2]-'A'])>1)cout<<"1110";
	else cout<<"1111";
	return 0;
}
/*
- 两张车票对应的座位是否在同一节车厢；
- 两张车票对应的座位是否在同一节车厢的同一排；
- 两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
- 两张车票对应的座位是否相邻。
*/
