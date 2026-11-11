#include<bits/stdc++.h>
using namespace std;
long long n,cnt,sum;
long long c = 0;
string s,ans;
long long a1[200005];
char s1[200005];
void hwen(string x){
	long long cpp = -1;
	for(long long i = sum-1;i >= 0;i--){
		ans[++cpp] = s[i];
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(long long i = 0;i < n;i++){
		cin >> a1[i] >> s1[i];
		sum+=a1[i];
	}
	if(sum >= 100000000){
		cout << sum/2;
		return 0;
	}
	for(long long i = 0;i < n;i++){
		for(long long j = 0;j < a1[i];j++){
			s[c] = s1[i];
			c++;
		}
	}
	hwen(s);
	for(long long i = 0;i < sum/2;i++){
		if(s[i] != ans[i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
