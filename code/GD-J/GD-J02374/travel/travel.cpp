#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a == c){//chexiang
		cout << 1;
		int numa,numb;
		numa = (b[0] - '0') * 10 + (b[1] - '0');
		numb = (d[0] - '0') * 10 + (d[1] - '0');
		if(numa == numb){//pai
			cout << 1;
			char sta,stb;
			sta = b[2];stb = d[2];
			if((sta == 'F' && stb == 'D') || (sta != 'F' && sta != 'D' && stb != 'F' && stb != 'D')){//ce
				cout << 1;
				if(abs((int)(sta - stb)) == 1) cout << 1;
				else cout << 0;
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else cout << "0000";
	return 0;
} 
