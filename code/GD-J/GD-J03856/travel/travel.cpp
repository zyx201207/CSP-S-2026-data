#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
string s1, s2;
int a, b;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>a>>s1>>b>>s2;
	if(a == b){
		cout<<1;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout<<1;
			if(((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || ((s1[2] == 'A' || s1[2] == 'B') && (s2[2] == 'A' || s2[2] == 'B'))){
				cout<<1;
				if((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B')
				 || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')) cout<<1<<"\n";
				else cout<<"0\n";
			}
			else cout<<"00\n";
		}
		else cout<<"000\n";
	}
	else cout<<"0000\n";
	return 0;
}
