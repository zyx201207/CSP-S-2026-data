#include<bits/stdc++.h>
using namespace std;
int n,a;
char c;
string s,huiwen;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
        cin >> a >> c;
        s += a*c;
	}
	return 0;
}

