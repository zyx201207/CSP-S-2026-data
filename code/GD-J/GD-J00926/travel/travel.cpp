#include<iostream>
#include<string>

using namespace std;

string c1, s1, c2, s2;
int ax, ay, az, bx, by, bz;
bool ans1, ans2, ans3, ans4;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	ax = (c1[0]-'0')*10+(c1[1]-'0');
	ay = (s1[0]-'0')*10+(s1[1]-'0');
	az = s1[2]-'A';
	bx = (c2[0]-'0')*10+(c2[1]-'0');
	by = (s2[0]-'0')*10+(s2[1]-'0');
	bz = s2[2]-'A';
	if(ax == bx){
		ans1 = 1;
		if(ay == by){
			ans2 = 1;
			if((az < 3 && bz < 3) || (az >= 3 && bz >= 3)){
				ans3 = 1;
				if(max(az-bz, bz-az) == 1) ans4 = 1;
			}
		}
	}
	cout << ans1 << ans2 << ans3 << ans4;
	return 0;
} 
