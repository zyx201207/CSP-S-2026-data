//GZ-J00220	  遵义市南白初级中学   吴濬嘉
#include <bits/stdc++.h>
using namespace std;
string s;
long long ans,maxn;
int n;
long long b[30];
char d[30];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		long long a;
		char c;
		cin >> a >> c;
		b[c - 'a'] += a;
		d[c-'a'] = c;
	}
	for (int i = 1;i <= 26;i++)	
		if(d[i]>='a' && d[i] <= 'z')	s += d[i];	
	maxn = b[1];
	for (int i = 2;i <= 26;i++)
		if (b[i] && b[i] > maxn)	maxn = b[i];
	ans = 0;
	int m = s.size() / 2;
	for (int i = 0;i < m;i++){
		 if (s[i] != s[2 * m - i])	ans++;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

