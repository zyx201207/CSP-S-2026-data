#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ans1 = 0,ans2 = 0,ans3 = 0,ans4 = 0;
const char D[10][2] = {{'A','B'},{'B','A'},{'B','C'},{'C','B'},{'D','F'},{'F','D'}};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	cin >> a >> b >> c >> d;
	if(a == c){
		ans1 = 1;
	}
	int sb = b[0] * 10 + b[1];
	int sd = d[0] * 10 + d[1];
	if(ans1 == 1 && sb == sd){
		ans2 = 1;
	}
	if(ans2 == 1){
		if(b[2] == 'A' || b[2] == 'B' || b[2] == 'C'){
			if(d[2] == 'A' || d[2] == 'B' || d[2] == 'C'){
				ans3 = 1;
			}
		}else{
			if(d[2] == 'D' || d[2] == 'F'){
				ans3 = 1;
			}
		}
	}
	bool ok = false;
	for(int i = 0;i <= 5; i++){
		if(b[2] == D[i][0] && d[2] == D[i][1]){
			ok = true;
		}
	}
	if(ans3 == 1 && ok){
		ans4 = 1;
	}
	cout << ans1 << ans2 << ans3 << ans4;
	return 0;
}
