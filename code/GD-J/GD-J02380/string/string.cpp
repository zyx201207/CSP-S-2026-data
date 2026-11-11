#include <bits/stdc++.h>

using namespace std;

int n;
int a[200005];
char c[200005]; 
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0) -> ios::sync_with_stdio(0); 
	
	bool same = 1;
	long long len = 0; 
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		for(int j = 1;j <= a[i];j++){
			s += c[i];
		}
		len += a[i];
		if(i > 1){
			if(c[i] != c[i -1])
				same = 0;
		} 
	}
	s = " " + s; 
	if(same or n == 1){
		cout << 0;
		return 0; 
	}
	
	long long cnt = 0;
	string left,right;
	if(len & 1){
		long long mid = (len + 1) / 2;
		left = s.substr(1,mid - 1),right = s.substr(mid + 1);
		reverse(right.begin(),right.end());
		for(int i = 0;i < left.size();i++){
			if(left[i] != right[i])
				cnt++;
		}
	}
	else{
		long long mid = len / 2;
		left = s.substr(1,mid),right = s.substr(mid + 1);
		reverse(right.begin(),right.end());
		for(int i = 0;i < left.size();i++){
			if(left[i] != right[i])
				cnt++;
		}
	}
	cout << cnt;
	return 0;

} 
