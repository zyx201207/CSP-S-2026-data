#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,sum; 
long long a[500005]; 
stack<long long> s1;
stack<long long> s2;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	sort(a,a+n);
	int mid=n/2;
	for(int i=0;i<mid;i++) {
		s1.push(a[i]);
	}
    for(int i=n;i>mid;i--) {
    	s2.push(a[i]);
	}
	while(m) {
		int y1,y2;
		y1=s1.top();
		y2=s2.top();
		if(a[mid]-y1<=y2-a[mid]) {
			s1.pop();
			if(m-(a[mid]-y1)>=0) {
				m=m-(a[mid]-y1);
		    	ans++;
			}
		}
		else {
			s2.pop();
			if(m-(y2-a[mid])>=0) {
				m=m-(y2-a[mid]);
			    ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
