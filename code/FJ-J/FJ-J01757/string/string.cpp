#include <bits/stdc++.h>
using namespace std;
string s="";
long long n,cnt,cnt1;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		long long a;
		string c;
		cin >> a >> c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
		cnt+=a;
	}
	for(int i=0;i<=cnt/2-1;i++){
		if(s[i]!=s[cnt-1-i]){
			cnt1++;
		}
	}
	cout << cnt1;
	return 0;
} 
