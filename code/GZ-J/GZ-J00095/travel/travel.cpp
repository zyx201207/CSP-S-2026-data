// GZ-J00095 贵阳市白云区华师一学校 王舒越 
#include<bits/stdc++.h>
#define ll long long
#define MAXN 100010
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else if(s1[0]!=s2[0] || s1[1]!=s2[1]) cout<<"1000";
	else if(s1[2]<='C' && s2[2]>='D') cout<<"1100";
	else if(s2[2]<='C' && s1[2]>='D') cout<<"1100";
	else if(char(s1[2]+1)!=s2[2] && char(s1[2]-1)!=s2[2]) cout<<"1110";
	else cout<<"1111";
	return 0;
}
