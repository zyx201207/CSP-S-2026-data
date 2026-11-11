#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in", "r",stdin);
	freopen("string.out", "w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n1;
	cin >> n1;
	
	struct asd{
		long long begin;
		long long end;
		char c1;
	};
	long long k=0;
	long long l=0;
	asd s[n1];
	for(int i=0; i<n1; i++){
		s[i].begin = k;
		int a;
		cin >> a;
		l += a;
		k += a;
		s[i].end = k-1;
		cin >> s[i].c1;
		
	}
	
	long long ans=0;
	int i=0,j=n1-1;
	for(int t=0; t<l/2; t++){
		if(t>s[i].end) i++;
		if(l-1-t<s[j].begin) j--;
		if(s[i].c1 != s[j].c1){
			ans++;
			//cout << s[i].c1 << ' ' << s[j].c1 << '\n';
		}
	}
	
	/*for(int i=0; i<n1; i++){
		cout << s[i].begin << s[i].end << s[i].c1 << '\n';
	}*/
	cout << ans;
	return 0;
}
