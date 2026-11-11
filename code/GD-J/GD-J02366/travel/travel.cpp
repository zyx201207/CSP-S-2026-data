#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool twl = true;
#define endl "\n"
string a1,a2,b1,b2; 
void solve(){
	cin >> a1 >> a2 >> b1 >> b2;
	if(a1 == b1){
		cout << 1;
	}else{
		cout << 0;
		twl = false;
	}
	if(twl && a2[0] == b2[0] && a2[1] == b2[1]){
		cout << 1;
	}else{
		cout << 0;
		twl = false;
	}if(twl && (b2[2] == 'A' || b2[2] == 'B' || b2[2] == 'C')&&(a2[2] == 'A' || a2[2] == 'B' || a2[2] == 'C')){
		cout << 1;
	}else if(twl && (b2[2] == 'D' || b2[2] == 'F')&&(a2[2] == 'D' || a2[2] == 'F')){
		cout << 1; 
	}else{
		twl = false;
		cout << 0;
	}if(twl && (max(int(b2[2]),int(a2[2])) - min(int(b2[2]),int(a2[2])))==1){
		cout << 1;
	}else cout << 0;
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
