#include<bits/stdc++.h>
using namespace std;
#define int long long
#define File(x) (freopen(x".in","r",stdin),freopen(x".out","w",stdout))
const int N=2e5+5,mod=1e9+7;
string s1,s2,t1,t2; 
signed main(){
	File("travel");
	cin>>s1>>t1>>s2>>t2;
	if(s1!=s2)return puts("0000"),0;
	if(t1[0]!=t2[0]||t1[1]!=t2[1])return puts("1000"),0;
	if((t1[2]<='C')!=(t2[2]<='C'))return puts("1100"),0;
	if(abs((int)t1[2]-(int)t2[2])!=1)return puts("1110"),0;
	else return puts("1111"),0;
	return 0;
}