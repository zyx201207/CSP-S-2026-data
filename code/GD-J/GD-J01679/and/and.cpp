#include <bits/stdc++.h>
using namespace std;

struct Node {
	long long a=0;
	int cnt=0;
};

bool cmp(Node a, Node b) {
	return ((a.a!=b.a)? a.a>b.a:a.cnt>b.cnt);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n=0,m=0;
	cin>>n>>m;
	vector<Node> s(n);
	for(int i=0;i<n;i++) {
		cin>>s[i].a;
	}
	for(int i=0;i<n;i++) {
		long long x=s[i].a;
		while(x>0) {
			if(x & 1) {
				s[i].cnt++; 
			}
			x=x>>1;
		}
	}
	sort(s.begin(),s.end(),cmp);
	
	long long ans=s[0].a;
	for(int i=1;i<m;i++) {
		ans&=s[i].a;
	}
	cout<<ans;
	return 0;
}
