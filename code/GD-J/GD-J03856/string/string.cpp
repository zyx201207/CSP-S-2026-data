#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
using ll = long long;
ll ans;
int n, mat[200002];
char mata[200002];
bool matp = false, matap = false;
int n2, ma[200002];
char ma2[200002], ins;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>mat[i]>>mata[i];
	}
	for(int i = 1; i <= n; i++){
		if(mata[i] != ins){
			ins = mata[i];
			n2++;
			ma2[n2] = mata[i];
		}
		ma[n2] += mat[i];
	}
	if(n2 < 3){
		cout<<min(ma[1], ma[2]);
		return 0;
	}if(n2 == 3 && ma2[1] == ma2[3]){
		if(ma[2] < abs(ma[1] - ma[3])) cout<<ma[2];
		else cout<<abs(ma[1] - ma[3]);
		return 0;
	}
	for(int i = 1; i <= n2 / 2; i++){
		if(ma2[i] != ma2[n2 + 1 - i]){
			ans += max(ma[i], ma[n2 + 1 - i]) - abs(ma[i] - ma[n2 + 1 - i]);
			if(ma[i] != ma[n2 + 1 - i] && abs((n2 + 1 - i) - i) == 2) ans += abs(ma[i] - ma[n2 + 1 - i]);
		}
		if(ma2[i] == ma2[n2 + 1 - i] && ma[i] != ma[n2 + 1 - i]){
			
			if(ma[i] > ma[n2 + 1 - i]){if(ma[i] != ma[n2 + 1 - i] && abs((n2 + 1 - i) - i) == 2) ans += abs(ma[i] - ma[n2 + 1 - i]);
				ans += ma[i] - ma[n2 + 1 - i];
				ma[i] -= ma[i] - ma[n2 + 1 - i];
				ma[i + 1] += ma[i] - ma[n2 + 1 - i];
			}
			if(ma[i] < ma[n2 + 1 - i]){if(ma[i] != ma[n2 + 1 - i] && abs((n2 + 1 - i) - i) == 2) ans += abs(ma[i] - ma[n2 + 1 - i]);
				ans += ma[n2 + 1 - i] - ma[i];
				ma[n2 + 1 - i] -= ma[n2 + 1 - i] - ma[i];
				ma[n2 - i] += ma[n2 + 1 - i] - ma[i];
			}
		}
		
	}
	cout<<ans<<"\n";
	return 0;
}
