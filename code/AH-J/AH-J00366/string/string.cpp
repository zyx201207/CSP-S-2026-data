#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //shanzhushi
    long long cns=0;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		char p;
		int c;
		cin >> c >> p;
		cns +=c;
		for(int k=0;k<c;k++){
			s[k]=p;
		}
	}
	int cnt=0;
	for(int j=0;j<cns/2;j++){
		if(s[j]!=s[cns-1] && s[cns-1]!=' '){
			cnt++;
		}
	}
	cout << cnt;
    return 0;
}
