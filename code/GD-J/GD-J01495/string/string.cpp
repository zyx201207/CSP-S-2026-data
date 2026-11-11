#include<bits/stdc++.h>
using namespace std;
long long n;
class my_que {
	public:
		pair<long long,char> a[512345];
		int nxt[512345],lst[512345];
		int frt = 0,bck = 0;
		int siz = 0;
		int _Cnt = 0;
		pair<long long,char> front() {
			return a[frt];
		}
		pair<long long,char> back() {
			return a[bck];
		}
		void pop_back() {
			nxt[lst[bck]] = 0;
			bck = lst[bck];
			--siz;
		}
		void pop_front() {
			lst[nxt[frt]] = 0;
			frt = nxt[frt];
			--siz;
		}
		void push_back(pair<long long,char> t) {
			++_Cnt;
			if(siz == 0) {
				siz = 1;
				a[_Cnt] = t;
				frt = bck = _Cnt;
				a[_Cnt] = t;
				return;
			}
			a[_Cnt] = t;
			nxt[bck] = _Cnt;
			lst[_Cnt] = bck;
			bck = _Cnt;
			++siz;
		}
		void push_front(pair<long long,char> t) {
			++_Cnt;
			if(siz == 0) {
				siz = 1;
				a[_Cnt] = t;
				frt = bck = _Cnt;
				a[_Cnt] = t;
				return;
			}
			a[_Cnt] = t;
			nxt[_Cnt] = frt;
			lst[frt] = _Cnt;
			frt = _Cnt;
			++siz;
		}
		int size() {
			return siz;
		}
		my_que() {
			memset(nxt,0,sizeof(nxt));
			memset(lst,0,sizeof(lst));
		}
};//deque
my_que v;
long long solve_TMLROCK() {
	long long ans = 0;
	while(v.size()) {
		if(v.size() == 1)break;
		long long t1 = v.front().first;
		char c1 = v.front().second;
		long long t2 = v.back().first;
		char c2 = v.back().second;
		if(v.size() == 2) {
			if(c1 == c2) break;
			else {
				return ans + min(t1,t2);
			}
		}
		v.pop_back();
		v.pop_front();
//		cout<<"\t-->"<<c1<<c2<<t1<<' '<<t2<<endl;
		if(c1==c2) {
			if(t1 > t2) {
				v.push_front(make_pair(t1-t2,c1));
			} else if (t1 < t2) {
				v.push_back(make_pair(t2-t1,c2));
			}
		} else {
			if(t1 > t2) {
				v.push_front(make_pair(t1-t2,c1));
				ans += t2;
			} else if (t1 < t2) {
				v.push_back(make_pair(t2-t1,c2));
				ans += t1;
			} else ans += t1;
		}
	}
	return ans;
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char x;
	long long y;
	for(int i = 0; i<n; ++i) {
		cin>>y>>x;
		v.push_back(make_pair(y,x));
	}
	cout<<solve_TMLROCK();
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
