#include<bits/stdc++.h>
using namespace std;
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
int a[5] = {1,1,1,2,2};
string s1,s2,x1,x2;
int main(){
	fre("travel");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s1 >> s2 >> x1 >> x2;
	if(s1==x1){
		if(s2[0]==x2[0]&&s2[1]==x2[1]){
			if(a[s2[2]-'A']==a[x2[2]-'A']){
				if(s2[2]-x2[2]==1||s2[2]-x2[2]==-1) cout << "1111";
				else cout << "1110";
			}
			else cout << "1100";
		}
		else cout << "1000";
	}
	else cout << "0000";
	return 0;
}
