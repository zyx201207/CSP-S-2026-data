#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
//int a[N];
//char c[N];
vector<pair<int, char>> words; 
// 对于第i个：有a:int个c:char 

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	int n; 
	cin >> n;
	words.push_back({0,0});
	
	if (n==1){
		cout << 0 << endl;
		return 0;
	}
	
	int cnt=0; // 有cnt个字符 
	bool samea=false, samec=false;
	int lasta;
	char lastc;
	for (int i=1;i<=n;i++){
//		cout << i;
//		cin >> a[i] >> c[i];
		int a;
		char c;
		cin >> a >> c;
		if (lasta==a){
			samea=true;
		} else samea=false;
		if(lastc==c) samec=true;
		else samec=false;
		lasta=a;lastc=c;
//		cout << a << " " << c;
		cnt += a;
		words.push_back({a, c});
	}
	
	if (samea || samec){
		cout << 0;
		return 0;
	}
	
	
	string s=" ";
	for (int i=1;i<=cnt;i++){
		for (int j=1;j<=words[i].first;j++){
			s+=words[i].second;
		}
	}
	long long ans=0;
	s += " ";
	int i=1, j=cnt; // i是left  j是right 
	
//	cout << cnt;
	while(i<j){
		// 所以i>j时停止
		if(s[i]!=s[j]) ans++; 
		i++; j--;
		
	}
	cout << ans;
	
	return 0;
} 
