#include<bits/stdc++.h>
using namespace std;

char c1[10], s1[10], c2[10], s2[10];
int t[10];

int main(){
	freopen("travel.in","r", stdin);
	freopen("travel.out","w", stdout); 
	scanf("%s%s%s%s", c1 + 1, s1 + 1, c2 + 1, s2 + 1);
	int v1 = 0, v2 = 0;
	for(int i = 1; i <= 2; i++){
		v1 = v1 * 10 + c1[i];
		v2 = v2 * 10 + c2[i];
	}
	if(v1 == v2)
		t[1] = 1;
	v1 = (s1[1] - '0') * 10 + s1[2] - '0';
	v2 = (s2[1] - '0') * 10 + s2[2] - '0';
	if(v1 == v2)
		t[2] = 1;
	v1 = s1[3] - 'A' + 1;
	v2 = s2[3] - 'A' + 1;
	if((v1 <= 3 && v2 <= 3) || (v1 >= 4 && v2 >= 4)){
		t[3] = 1;
	}
	if(abs(v1 - v2) == 1)
		t[4] = 1;
	for(int i = 1; i <= 4; i++){
		printf("%d", t[i]);
		if(t[i] == 0){
			t[i + 1] = 0;
		}
	}
	return 0;
}
//Trick||Treat!
