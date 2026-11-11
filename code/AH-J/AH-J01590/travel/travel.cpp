#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
int h[305];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	h['A'] = 1;
	h['B'] = 2;
	h['C'] = 3;
	h['D'] = 5;
	h['F'] = 6;
	cin>>a>>b>>c>>d;
	if(a == c){
		if(b[0] == d[0] && b[1] == d[1]){
			if(h[b[2]]<4 && h[d[2]]<4 || h[b[2]]>4 && h[d[2]]>4){
				if(abs(h[b[2]]-h[d[2]]) == 1){
					cout<<"1111\n";
				}else{
					cout<<"1110\n";
				}
			}else{
				cout<<"1100\n";
			}
		}else{
			cout<<"1000\n";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
