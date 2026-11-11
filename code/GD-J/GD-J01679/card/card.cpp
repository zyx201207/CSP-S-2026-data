#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	vector<int> a(n,0);
	vector<int> b(m,0);
	vector<int> s;
	bool p=false;
	if(n>500 || m>200) p=true;
	for(int i=0;i<m;i++) {
		b[i]=0;
	}
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if(p) b[a[i]-1]=i+1;
	}
	if(!p) {
		for(int i=0;i<n;i++) {
			s.clear();
			for(int j=i;j<n;j++) {
				long long w=s.size();
				for(int k=0;k<w;k++) {
					if(s[k]==a[j]) {
						s.erase(s.begin()+k,s.end());
						break;
					}
				}
				s.push_back(a[j]);
			}
			for(auto ch:s) {
				b[ch-1]++;
			}
		}
	}
	for(int i=0;i<m;i++) {
		cout<<b[i]<<" ";
	}
	
	return 0;
}
