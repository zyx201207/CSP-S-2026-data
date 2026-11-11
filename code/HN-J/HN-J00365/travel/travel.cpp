#include<iostream>
#include<string>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string out_z = "0000";
	int c1;
	int c2;
	string s1;
	string s2;
	cin >> c1;
	cin >> s1;
	cin >> c2;
	cin >> s2;
	
	if (c1 == c2){
		out_z[0] = '1';
	}
	
	if (s1[0] == s2[0]){
		if (s1[1] == s2[1]){
			out_z[1] = '1';
			if (s1[2] == 'A'){
				if (s2[2] == 'B'){
					out_z[2] = '1';
					out_z[3] = '1';
				}
				if (s2[2] == 'C'){
					out_z[2] = '1';
				}
				
			}
			if (s1[2] == 'B'){
				if (s2[2] == 'A'){
					out_z[2] = '1';
					out_z[3] = '1';
				}
				if (s2[2] == 'C'){
					out_z[2] = '1';
					out_z[3] = '1';
				}
				
			}
			if (s1[2] == 'C'){
				if (s2[2] == 'A'){
					out_z[2] = '1';
				}
				if (s2[2] == 'B'){
					out_z[2] = '1';
					out_z[3] = '1';
				}
				
			}
			if (s1[2] == 'D'){
				if (s2[2] == 'F'){
					out_z[2] = '1';
					out_z[3] = '1';
				}
				
			}
			if (s1[2] == 'F'){
				if (s2[2] == 'D'){
					out_z[2] = '1';
					out_z[3] = '1';
				}
			}
			
		}
	}
	
	cout << out_z;
	
	return 0;
}


