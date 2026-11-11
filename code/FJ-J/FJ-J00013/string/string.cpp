#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

struct S{
	int a;
	char c;
};
vector<S> s;

int n;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	s.resize(n+1);
	for(int i = 1;i <= n;i++){
		cin >> s[i].a >> s[i].c;
	}
	
	int l = 1;
	int r = n;
	int cnt = 0;
	while(l <= r){
		if(s[l].a >= s[r].a){
			s[l].a -= s[r].a;
			if(s[l].c != s[r].c){
				cnt += s[r].a;
			}
			
			s[r].a = 0;
		}
		else{
			s[r].a -= s[l].a;
			if(s[l].c != s[r].c){
				cnt += s[l].a;
			}
			
			s[l].a = 0;
		}
		
		if(s[l].a == 0){
			l++;
		}
		if(s[r].a == 0){
			r--;
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}

