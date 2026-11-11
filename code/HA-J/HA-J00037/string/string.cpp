#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n; 
	
	string s;
	s+=' ';
	int sum = 0;
	for(int i = 0;i < n;i++){
		int a;
		char c;
		cin >> a >> c;
		for(int j = 0;j < a;j++){
			s+=c;
		}
		sum+=a;
	}
	//cerr << s<<"\n\n";
	//cerr << sum << "\n\n";
	
	int cnt = 0;
	for(int i = 1;i < sum/2;i++){
		//cerr << "i= " << i << "sum+1-i= " << sum+1-i;
		//cerr << "s[i]= " << s[i] << "s[sum+1-i]= "<<s[sum+1-i] << "\n\n";
		if(s[i] != s[sum+1-i]){
			cnt++;
		}
	}
	
	cout << cnt << "\n";
	
	return 0;
}