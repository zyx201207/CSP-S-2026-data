#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	char c1[4];
	char s1[4];
	char c2[4];
	char s2[4];
	cin >> c1 >> " " >> s1 >> " " >> c2 >> " " >> s2;
	int ans[5];
	if(c1 == c2){
		ans[0] = 1;
	}else{
		ans[0] = 0;
	}
	if(ans[0] == 1 && s1[0]+s1[1] == s2[0]+s2[1]){
		ans[1] == 1;
	}else{
		ans[1] == 0;
	}
	if(ans[1] == 1 && s1[2] ="A" || s1[2] ="B" || s1[2] ="C" && s2[2] ="A" || s2[2] ="B" || s2[2] ="C"){
		ans[2] == 1;
	}if else(ans[1] == 1 && s1[2] ="D" || s1[2] ="E" && s2[2] ="D" || s2[2] ="E"){
		ans[2] == 1;
	}else{
		ans[2] == 0;
	}
	if(s1[2] == s2[2] + 1 || s1[2] == s2[2] - 1){
		ans[3] == 1;
	}else{
		ans[3] == 0;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
