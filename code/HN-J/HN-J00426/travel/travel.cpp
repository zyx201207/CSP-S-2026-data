//travel
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
constexpr int N=1e5+5,M=5*N,K=5000;
string n,m,q,p;
map<char,int> mp;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	mp['A']=1;
	mp['B']=2;
	mp['C']=3;
	mp['D']=4;
	mp['F']=5;
	
	cin >> n >> m >> q >> p;
	if(n==q) cout << 1;
	else cout << 0;
	
	if(n==q&&m[0]==p[0]&&m[1]==p[1]) cout << 1;
	else cout << 0;
	
	if(n==q&&m[0]==p[0]&&m[1]==p[1]&&((m[2]<='C'&&p[2]<='C')||(m[2]>='D'&&p[2]>='D')))cout << 1;
	else cout << 0;
	
	if(n==q&&m[0]==p[0]&&m[1]==p[1]&&((m[2]<='C'&&p[2]<='C')||(m[2]>='D'&&p[2]>='D'))&&abs(mp[m[2]]-mp[p[2]])==1){
		cout << 1;
	}else cout << 0;
	return 0;
}
/*

02 01A 02 01B
*/
