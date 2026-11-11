#include<bits/stdc++.h>
using namespace std;
string s1, s2, c1, c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){//同车厢 
		if(s1[0]==s2[0] && s1[1]==s2[1]){//同排 
			if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C')){//同侧 
				if(abs(s1[2]-s2[2])==1)//相邻
					cout << 1111 << "\n"; 
				else cout << 1110 << "\n";
			}
			else cout << 1100 << "\n";
		}
		else cout << 1000 << "\n";
	}
	else cout << 0000 << "\n";
	return 0;
} 
