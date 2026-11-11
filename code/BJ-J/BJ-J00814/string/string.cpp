#include <bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
string s,s1;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>c[i];
		for(int j = 1;j <= a[i];j++){
			s += c[i];
		}
	}
	int len = s.size();
	for(int i = 0;i < len/2;i++){
		s1 += s[len/2-i-1];
	}
	int cnt = 0;
	if(len % 2 == 0){
		for(int i = len/2;i < len;i++){
			if(s[i] != s1[i-len/2]) cnt++;
		}
	}
	else{
		for(int i = len/2+1;i < len;i++){
			if(s[i] != s1[i-len/2-1]) cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
