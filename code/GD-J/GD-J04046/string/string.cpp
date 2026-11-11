#include<iostream>
#include<cstdio>
using namespace std;

int n, centre;
long long length, pos, cnt; 
struct node{
	char c;
	int x;
}s[200005];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.ans", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		char c;
		cin >> x >> c;
		s[i].x = x;
		s[i].c = c;
		length += x;
	}
//	length /= 2;
//	long long t = 0;
//	for (int i = 1; i <= n; i++){
//		t += s[i].x;
//		if (t >= length){
//			centre = i;
//			break;
//		}
//	}
	int l = 1, r = n;
	while (l < r){
		if (s[l].c == s[r].c){
			if (s[l].x >= s[r].x){
				s[l].x -= s[r].x;
				s[r].x -= s[r].x;
			} 
			else{
				s[r].x -= s[l].x;
				s[l].x -= s[l].x;
			}
			if (s[l].x <= 0) l++;
			if (s[r].x <= 0) r--;
		}
		else{
			if (s[l].x >= s[r].x){
				cnt += s[r].x;
				s[l].x -= s[r].x;
				s[r].x -= s[r].x;
			} 
			else{
				cnt += s[l].x;
				s[r].x -= s[l].x;
				s[l].x -= s[l].x;
			}
			if (s[l].x <= 0) l++;
			if (s[r].x <= 0) r--;
		}
	}
	cout << cnt;
	return 0;
	
} 
