#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool flag=true;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) flag=false;
	cout<<(flag? 1:0);
	if(s1[0]!=s2[0]||s1[1]!=s2[1]) flag=false;
	cout<<(flag? 1:0);
	if(s1[2]<='C'&&s2[2]>='D'||s1[2]>='D'&&s2[2]<='C') flag=false;
	cout<<(flag? 1:0);
	if(abs(ll(s1[2])-ll(s2[2]))!=1) flag=false;
	cout<<(flag? 1:0);
	return 0;
}
