#include <bits/stdc++.h>
using namespace std;
long long a[200005];
string s,t={1},st={1};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> s[i];
		for(long long j=1;j<=a[i];j++){
			t+=s[i];
		}
	}
	st = t;
	long long o=(t.size()+2-1)/2;
	for(int i=0;i<=o;i++){
		swap(t[i],t[t.size()-i]);
	}
	long long ans=0;
	long long u = t.size()-1;
	for(long long i=0;i<=u;i++){
		if(t[i] != st[i]){
			ans++;
		}
	}
	cout <<  ans/2;
	return 0;
}
