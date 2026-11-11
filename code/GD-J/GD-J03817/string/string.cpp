#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt = 0;
int q[200005];
string s = "";
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int i = 1;i <= a;i++){
			s += c;
		}
	}
	int len = s.size();
	string v = "";
	for(int i = len - 1;i >= 0;i--){
		v += s[i];
		q[s[i]] ++;
	}
	if(s == v){
		cout<<0;
		return 0;
	}
	int flag = 1;
	for(int i = 0;i < len;i++){
		if(s[i] != v[i]) cnt++;
	}
	for(int i = 97;i <= 122;i++) if(q[i] > 1) flag = 0;
	if(flag == 1){
		cout<<len - 1;
		return 0;
	}
	cnt = cnt / 2;
	if(cnt % 2 == 1) cnt = cnt + 1;
	cout<<cnt;
	return 0;
}
