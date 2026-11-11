#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int a;
	char c;
	for(int i=1; i<=n; i++) {
		cin>>a>>c;
		for(int j=1; j<=a; j++) {
			s+=c;
		}
	}
	long long  mid=s.length()/2;
	long long  L=s.length();
	long long  cnt=0;
	if(L%2==1) {
		for(int i=0,j=L-1; i<mid&&j>mid; i++,j--) {
			if(s[i]!=s[j]) {
				cnt++;
			}

		}
	}else{
		for(int i=0,j=L-1; i<mid&&j>=mid; i++,j--) {
			if(s[i]!=s[j]) {
				cnt++;
			}

		}
	}


	cout<<cnt;
	return 0;
}

