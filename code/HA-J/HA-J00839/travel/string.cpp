#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
string t;
int a[MAXN];
char c[MAXN];
long long cnt;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	for (int i=0;i<n;i++) {
		while (a[i]--) t+=c[i];
	}
	long long l=t.size();
	for (long long i=l-1;i>=l/2;i--){
		if(t[i]!=t[l-i-1]) cnt++;
	}
	cout<<cnt;
	return 0;
}




