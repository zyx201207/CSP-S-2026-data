#include<bits/stdc++.h>
using namespace std;
int pan (string x){
	if(x[2] == 'A' || x[2] == 'B' || x[2] == 'C'){
		return 1;
	}else{
		return 2;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1 , c2 , s1 , s2;
	int o1 = 0 , o2 = 0 , o3 = 0 , o4 = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		o1 = 1;
		if(s1[0] + s1[1] == s2[0] + s2[1]){
			o2 = 1;
			if(pan(s1) == pan(s2)){
				o3 = 1;
				if(!((s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'A'))){
					o4 = 1;
				}
			}
		}
	}
	cout << o1 << o2 << o3 << o4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
