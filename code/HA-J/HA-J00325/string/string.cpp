#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt,l,r;
char c;
vector<char>v;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	cin>>n;
	for(long long i=1; i<=n; i++) {
		cin>>a>>c;
		cnt+=a;
		for(long long j=1; j<=a; j++) {
			v.push_back(c);
		}
	}
	l=cnt/2;
	if(cnt%2==0) r=cnt/2+1;
	else {
		cnt--;
		r=cnt/2+2;
	}
	while(r!=v.size()+1) {
		if(v[l]==v[r]) {
			cnt-=2;
			l--;
			r++;
		} else {
			l--;
			r++;
		}
	}
	cout<<cnt/2;
	return 0;
}

