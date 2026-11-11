#include <bits/stdc++.h>
using namespace std;

pair <long long, char> s[200005], s1[200005], s2[200005];
pair <long long, char> s3[200005], s4[200005];
long long n, slen, s1len, s2len, idx = 1;
void func1(){
	for(long long i = 1;i <= s1len;i++) s3[i] = s1[i];
	for(long long i = 1;i <= s2len;i++) s4[i] = s2[i];
}
int main(){
	//初始化 
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	s1[0].second = 'A', s[0].first = -1;
	//输入 
	cin >> n;
	for(long long i = 1;i <= n;i++){
		long long a;
		char b;
		cin >> a >> b;
		if(b == s[idx - 1].second) s[idx - 1].first += a;
		else{
			s[idx].first = a, s[idx].second = b;
			idx++;
		}
		slen += a;
	}
	//分割 
	long long t = slen / 2, t2;
	idx--;
	for(long long i = 1;i <= idx;i++){
		if(s[i].first <= t){
			s1[i] = s[i];
			t -= s[i].first;
		}
		else{
			s1len = i;
			s1[i].first = t;
			s1[i].second = s[i].second;
			s[i].first -= t;
			t2 = i;
			if(slen % 2 == 1){
				if(s[i].first == 1) t2++;
				else s[i].first--;
			}
			break;
		}
	}
	for(long long i = t2;i <= idx;i++){
		s2[i - t2 + 1] = s[i];
	}
	s2len = idx - t2 + 1;
	//回文判断 
	long long d1 = 0, d2 = 0, p1, p2;
	//前半段 
	func1();
	p1 = 1, p2 = s2len; 
	while(p1 <= s1len && p2 >= 1){
		if(s3[p1].first < s4[p2].first){
			if(s3[p1].second != s4[p2].second) d1 += s3[p1].first;
			s4[p2].first -= s3[p1].first;
			p1++;
		}
		else if(s3[p1].first > s4[p2].first){
			if(s3[p1].second != s4[p2].second) d1 += s4[p2].first;
			s3[p1].first -= s4[p2].first;
			p2--;
		}
		else{
			if(s3[p1].second != s4[p2].second) d1 += s3[p1].first;
			p1++, p2--;
		}
	}
	//后半段
	func1();
	p1 = s1len, p2 = 1;
	while(p1 >= 1 && p2 <= s2len){
		if(s3[p1].first < s4[p2].first){
			if(s3[p1].second != s4[p2].second) d2 += s3[p1].first;
			s4[p2].first -= s3[p1].first;
			p1--;
		}
		else if(s3[p1].first > s4[p2].first){
			if(s3[p1].second != s4[p2].second) d2 += s4[p2].first;
			s3[p1].first -= s4[p2].first;
			p2++;
		}
		else{
			if(s3[p1].second != s4[p2].second) d2 += s3[p1].first;
			p1--, p2++;
		}
	} 
	if(d2 > d1) cout << d1;
	else cout << d2;
	return 0;
}

