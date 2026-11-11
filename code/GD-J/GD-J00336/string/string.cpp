/*#include <bits/stdc++.h>
using namespace std;
struct letter{
	char c;
	long long l,r;
}t1[200005],t2[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long sum = 1;
	for (int i = 1;i <= n;i++){
		int a;
		char c;
		cin >> a >> c;
		t1[i].c = c;
		t1[i].l = sum;
		sum += a;
		t1[i].r = sum;
		t2[i].c = t1[i].c;
		t2[i].l = t1[i].l;
		t2[i].r = t1[i].r;
	}
	reverse(t2+1,t2+n+1);
	long long mid = sum/2;
	long long ans = sum/2;
	long long l=1,r=1,li=1,ri=1;
	while (l <= mid && r <= mid){
		if (t1[li].c == t2[ri].c){
			
		}
	}
	return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
int t[100000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s = "";
	for (int i = 1;i <= n;i++){
		int a;
		char c;
		cin >> a >> c;
		for (int j = 1;j <= a;j++) s += c;
	}
	string p = s;
	reverse(p.begin(),p.end());
	if (s == p){
		cout << 0;
		return 0;
	}
	int ans = 0;
	for (int i = 1;i <= s.size()/2;i++){
		if (s[i] != s[s.size()-i+1]) ans++;
	}
	cout << ans;
	return 0;
}
