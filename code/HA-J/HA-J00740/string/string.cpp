#include<bits/stdc++.h>
using namespace std;

int n;
long long x[200009],xxx,ans,num = 1;
string s,c;

int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> x[i];
		cin >> s[i];
		for(int j = xxx;j <= xxx+x[i];j++){
			c[j] == s[i];
		}
		xxx+=x[i];
	}
	for(int i = 1;i <= xxx/2;i++){
		if(c[xxx/2+num] == c[xxx/2-num]){
			c[xxx/2+num] = 0;
			c[xxx/2-num] = 0;
		}else{
			ans++;
		}
		num++;
	}
	cout << ans;
	return 0;
}
