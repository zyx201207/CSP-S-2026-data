#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int a[200010];
char c[200010];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie();
	cout.tie();
	int n, i, cnt = 0;
	cin>>n;
	for(i = 1; i <= n; i++) cin>>a[i]>>c[i];
	for(i = 1; i <= n; i++)
	while(a[i]){ 
		s1[i] = c[i];
		a[i]--;
	}
	for(i = 1; i <= int(s1.size()); i++){
		s2[s1.size() - i + 1] = s1[i];
	}
	for(i = 1; i <= n; i++)
	if(s1[i] != s2[i]) cnt++;
	if(cnt - 1 >= 0) cout<<cnt-1<<endl;
	else cout<<cnt<<endl;
	return 0;
}
