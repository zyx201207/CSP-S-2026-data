//GZ-J00293 »Æçûä¿
#include<bits/stdc++.h>
using namespace std;
int f[4][2] = {'A','B',
			   'C','B',
			   'A','C',
			   'D','F',}
	,ff[3][2] = {'A','B',
			    'C','B',
			    'D','F',};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin >> s1 >> s3 >> s2 >> s4;
	if(s1 == s2)cout << "1";
	else{
		cout << "0000";
		return 0; 
	}
	if(s3[0] == s4[0] && s3[1] == s4[1])cout << "1";
	else{
		cout << "000";
		return 0;
	}
	bool fl = 0;
	for(int i = 0;i < 4;i++){
		if((f[i][0] == s3[2] && f[i][1] == s4[2])||
			(f[i][1] == s3[2] && f[i][0] == s4[2])){
			fl = 1;
			break;
		}
	}
	if(fl){
	 	cout << "1";
	}else{
		cout << "00";
		return 0;
	}
	fl = 0;
	for(int i = 0;i < 3;i++){
		if((ff[i][0] == s3[2] && ff[i][1] == s4[2])||
			(ff[i][1] == s3[2] && ff[i][0] == s4[2])){
			fl = 1;
			break;
		}
	}
	if(fl)cout << "1";
	else cout << "0";
	return 0; 
}
