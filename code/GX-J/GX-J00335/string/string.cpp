#include<bits/stdc++.h>
using namespace std;

long long n,a,cnt = 0;
string s = "",t = "";
char c;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++){
		cin >> a >> c;
		for(int i = 0;i < a;i++){
			s += c;
		}
	}
	int len = (long long)s.size();
	for(int i = len-1;i >= 0;i--){
		t += s[i];
		
	}
	for(int i = len-1;i >= 0;i--){
		if(t[i] != s[i]){
			cnt++;
		}
		
	}
    cout << cnt/2;

    return 0;
}
