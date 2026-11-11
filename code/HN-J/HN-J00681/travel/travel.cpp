#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1 , a2;
	char b1[5] , b2[5];
	bool ans = false;
	cin >> a1 >> b1 >> a2 >> b2;	
	if(a1 != a2){
		cout << "0000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(b1[0] != b2[0] || b1[1] != b2[1]){
		cout << 1000;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(!(((b1[2] == 'A' || b1[2] == 'B' || b1[2] == 'C') && (b2[2] != 'A' || b2[2] != 'B' || b2[2] != 'C')) || ((b1[2] != 'D' || b1[2] != 'F') && (b2[2] == 'D' || b2[2] == 'F')))){
		cout << 1100;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(b1[2] == 'F' && b1[2] == 'D'){
		cout << 1111;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	char a[3] =  {'A','B','C'};
	for(int i = 0;i < 3;i++){
		if(b1[2] == a[i] && (b2[2] == a[i-1] || b2[2] == a[i+1])){
			ans = true;
		}
	}
	if(ans){
		cout << 1111;
	}
	else{
		cout << 1110;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
