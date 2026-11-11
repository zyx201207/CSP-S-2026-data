#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string r1,r2,x1,x2;
	cin >> r1 >> r2 >> x1 >> x2;
	int num_r,num_x,row_r,row_x,site_r,site_x;
	num_r = (int)(r1[1] - '0') + (r1[0] - '0') * 10;
	num_x = (int)(x1[1] - '0') + (x1[0] - '0') * 10;
	row_r = (int)(r2[1] - '0') + (r2[0] - '0') * 10;
	row_x = (int)(x2[1] - '0') + (x2[0] - '0') * 10;
	site_r = (int)(r2[2] - 'A' + 1);
	site_x = (int)(x2[2] - 'A' + 1);
	if(site_r == 6)site_r--;
	if(site_x == 6)site_x--;
	
	if(num_r == num_x){
		cout << 1;
		if(row_r == row_x){
			cout << 1;
			if((site_r <= 3 && site_x <= 3) || (site_r > 3 && site_x > 3)){
				cout << 1 << (abs(site_r - site_x) == 1);
				
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	
	return 0;
} 
