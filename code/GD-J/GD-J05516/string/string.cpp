#include<bits/stdc++.h>
using namespace std;

#define int long long

struct node{
	int a;
	char c;
};

vector<node> s;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i=1;i<=n;i++){
		char y;
		int x;
		cin >> x >> y;
		s.push_back({x,y});
	}
	int l=0,r=n-1;
	int cnt=0;
	while (l < r){
		if (s[l].c == s[r].c){
			if (s[l].a > s[r].a){
				s[l].a -= s[r].a;
				r--;
			}
			else if(s[l].a < s[r].a){
				s[r].a -= s[l].a;
				l++;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			if (s[l].a > s[r].a){
				cnt += s[r].a;
				s[l].a -= s[r].a;
				r--;
			}
			else if(s[l].a < s[r].a){
				cnt += s[l].a;
				s[r].a -= s[l].a;
				l++;
			}
			else{
				cnt += s[r].a;
				l++;
				r--;
			}
		}
	}
	cout << cnt;
	return 0;
}
