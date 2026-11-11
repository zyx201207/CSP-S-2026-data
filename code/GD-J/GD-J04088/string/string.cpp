#include<bits/stdc++:h>
using namespace std;
string s[2005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n>>endl;
	cin >> ai >> ci;
	for (i=0;i <= ai*ci;i++){
		s[i] += ci;
	}
	
	int cnt;
	cnt = 0;
	for (i = 0;i <= s.size();i++){
		if s[i] != s[n-i];
		cnt++;
		
	}
	cout << cnt;
	return 0 ;
	
	
	
	
} 

