#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,cnt,s1,s2;
	char s3[3],s4[3];
	cin >> c1 >> s1 >> c1 >> s2;
	for(int i = 1;i < 3;i++){
		s3[i] = s1;
	}
	for(int j = 1;j < 3;j++){
		s4[j] = s2;
	}
	if (c1 == c2){
		cnt = cnt + 1000;
		if (s3[1] == s4[1]){
			cnt = cnt + 100;
			if(s3[2] == s4[2]){
				cnt = cnt + 10;
				if(s3[3] + 1 == s4[3]){
					cnt += 1;
			}
		}	
	}	
	}
	else if(c1 != c2){
		cnt += 0;
	}
	cout << cnt;
	return 0;
} 
