#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000006;
string str1,str2,str3,str4;
bool check_side(string a,string b){
	int a_num=(a[2]-'A')+1;
	int b_num=(b[2]-'A')+1;
	if(1<=a_num and a_num<=3 and 1<=b_num and b_num<=3) return true;
	if(4<=a_num and a_num<=5 and 4<=b_num and b_num<=5) return true;
	return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>str1>>str2>>str3>>str4;
	if(str1!=str3) cout<<"0000"<<"\n";
	else if(!(str2[0]==str4[0] and str2[1]==str4[1])) cout<<"1000"<<"\n";
	else if(!check_side(str2,str4)) cout<<"1100"<<"\n";
	else if(abs((str2[2]-'A')-(str4[2]-'A'))!=1) cout<<"1110"<<"\n";
	else cout<<"1111"<<"\n";
	return 0;
}
