#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

bool check(string x,string y,int a){
	if (a == 1){
		string nx,ny;
		for(int i = 0;i < x.size();i++){
			char c = x[i];
			if (c >= '0' && c <= '9') nx += c;
		}
		for (int i = 0;i < y.size();i++){
			char c = y[i];
			if (c >= '0' && c <= '9') ny += c;
		}
		return nx == ny;
	}else if (a == 2){
		char nx,ny;
		for(int i = 0;i < x.size();i++){
			char c = x[i];
			if (c >= 'A' && c <= 'F'){
				nx = c;
				break;
			}
		}
		for (int i = 0;i < y.size();i++){
			char c = y[i];
			if (c >= 'A' && c <= 'F'){
				ny = c;
				break;
			}
		}
		return (nx > 'C' && ny > 'C') || (nx <= 'C' && ny <= 'C');
	}else{
		char nx,ny;
		for(int i = 0;i < x.size();i++){
			char c = x[i];
			if (c >= 'A' && c <= 'F'){
				nx = c;
				break;
			}
		}
		for (int i = 0;i < y.size();i++){
			char c = y[i];
			if (c >= 'A' && c <= 'F'){
				ny = c;
				break;
			}
		}
		if (abs(nx-ny) == 1) return 1;
		return 0;	
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2) cout << "1";
	else cout << "0";
	
	if (c1 == c2 && check(s1,s2,1)) cout << "1";
	else cout << "0";
	
	if (c1 == c2 && check(s1,s2,1) && check(s1,s2,2)) cout << "1";
	else cout << "0";
	
	if (c1 == c2 && check(s1,s2,1) && check(s1,s2,2) && check(s1,s2,3)) cout << "1";
	else cout << "0";
	return 0;	
} 
