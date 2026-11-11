#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
string S,S2;
bool hw(string S3){
	long long L3 = S3.length();
	for(long long i = 0;i < L3;i++){
		if(S3[i] != S3[L3 - 1 - i]) return false;
	}
	return true;
}
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long cnt = 0;
	int n;
	cin >> n;
	for(long long i = 0;i < n;i++){
		cin >> a[i];
		cin >> c[i];
	}
	for(long long i = 0;i < n;i++){
		for(long long j = 0;j < a[i];j++){
            S = S+c[i];
		}
	}
	long long L = S.length();
	bool flag = false;
	if(hw(S)){
		cout << 0;
		flag = true;
    } else{
		for(long long i = 0;i < L;i++) S2[L - i-1] = S[i];
		for(long long i = 0;i < L;i++){
			if(S[i] != S2[i]) cnt++;
		}
	}
	if(!flag) cout << cnt/2;
	
	return 0;
}
