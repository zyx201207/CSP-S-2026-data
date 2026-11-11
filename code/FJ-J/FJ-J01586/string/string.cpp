#include<bits/stdc++.h>
using namespace std;
long long n,l,lb,cnt = 0;
string s,sl,sr;
struct wz{
	long long a;
	char c;
};
wz b[10000005];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(long long i = 0; i < n; i++) cin >> b[i].a >> b[i].c;
	for(long long i = 0; i < n; i++)
	{
		for(long long j = 0; j < b[i].a; j++) s += b[i].c;
	} 
	for(long long i = 0; i < n; i++) l += b[i].a;
	lb = l / 2 + 1;
	for(long long i = 0; i < lb; i++) sl += s[i];
	for(long long i = l - 1; i >= lb - 1; i--) sr += s[i];
	for(long long i = 0; i < lb; i++)
	{
		if(sl[i] != sr[i]) cnt++;
	}
	cout << cnt << endl;
	
	return 0;
}
