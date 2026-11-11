#include<bits/stdc++.h>
using namespace std;
long long s[30];
int main(){
	
	freopen("string.in.txt","r",stdin);
	freopen("string.out.txt","w",stdin);
	long long n,m=0,cnt=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		int a;
		cin >> a;
		char c;
		cin >> c;
		s[c-'a'+1]+=a;
		m=max(m,s[c-'a'+1]);
	}
	for(int i=1;i<=26;i++)cnt+=s[i];
	cnt-=m;
	cout << cnt;
	
	return 0;
} 
