#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
struct str {
	int a;
	char c;
};
stack<str> s1,s2;
const int MAX_N = 2*100000 + 5;
str num[MAX_N];
int n;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long sum=0;
	for(int i=1;i<=n;i++) {
		cin >> num[i].a >> num[i].c;
		sum += num[i].a;
	}
	int mid = sum / 2;
	int ma=mid,mb=mid,j=1;
	while(ma > 0) {
		if(ma > num[j].a) {
			s1.push({num[j].a,num[j].c});
			ma -= num[j].a;
		} else {
			s1.push({ma,num[j].c});
			ma = 0;
		}
		j++;
	}
	j = n;
	while(mb > 0) {
		if(mb > num[j].a) {
			s2.push({num[j].a,num[j].c});
			mb -= num[j].a;
		} else {
			s2.push({mb,num[j].c});
			mb = 0;
		}
		j--;
	}
	str f1={0,0},f2={0,0};
	long long ans=0;
	while(!s1.empty() || !s2.empty()) {
		if(f1.a == 0) {
			f1 = s1.top();
			s1.pop();
		}
		if(f2.a == 0) {
			f2 = s2.top();
			s2.pop();
		}
		if(f1.a > f2.a) {
			if(f1.c != f2.c) {
				ans += f2.a;
			}
			f1.a -= f2.a;
			f2.a = 0;
		} else {
			if(f1.c != f2.c) {
				ans += f1.a;
			}
			f2.a -= f1.a;
			f1.a = 0;
		}
	}
	cout << ans;
	return 0;
}

