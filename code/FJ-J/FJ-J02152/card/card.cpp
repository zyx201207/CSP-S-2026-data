#include<bits/stdc++.h>
using namespace std;

const int N=3e5+5;
int b[N];
int a[N];
int c[N];
stack<int>s;

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int t=1; t<=n; t++) {
		for(int i=t; i<=n; i++) {
			if(b[a[i]]==0) {
				b[a[i]]++;
				s.push(a[i]);
			} else {
				while(b[a[i]]!=0) {
					b[s.top()]--;
					s.pop();
				}
				b[a[i]]++;
				s.push(a[i]);
			}
		}
		for(int i=1; i<=m; i++) {
			if(b[i]!=0) {
				c[i]++;
				b[i]=0;
			}
		}
		while(s.size()){
			s.pop();
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<c[i]<<" ";
	}
	return 0;
}
