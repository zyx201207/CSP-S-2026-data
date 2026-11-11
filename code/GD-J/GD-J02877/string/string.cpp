#include <bits/stdc++.h>
using namespace std;

struct storage{
	int a;
	string c;
};

bool isthestring(string S, int L){
	for(int f = 0; f < L; f++){
		if(int(S[f]) != int(S[L - 1 - f])) return false;
	}
	return true;
}

int main(){
	int n, L = 0;
	cin >> n;
	storage list[n];
	for(int h = 0; h < n; h++){
		list[h].a = 0;
	}
	for(int i = 0; i < n; i++) cin >> list[i].a >> list[i].c;
	for(int j = 0; j < n; j++) L += list[j].a;
	string S[L];
	int count1 = 0;
	for(int k = 0; k < n; k++){
		for(int l = 0; l < list[k].a; l++){
			S[count1] = list[k].c;
			count1++;
		}
	}
	for(int x = 0; x < L / 2; x++){
		if(isthestring(S, L)){
			cout << x << endl;
			return 0;
		}
		S[L - 1 - x] = S[x];
	}
	cout << 0 << endl;
	return 0;
}
