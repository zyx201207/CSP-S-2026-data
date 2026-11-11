#include <bits/stdc++.h>
using namespace std;
string s;
string s_fan;
int is_huiwen(string a, string b)
{
	if(a == b) return 0;
	else return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 0;i<n;i++){
		long long a;
		char c;
		cin >> a >> c;
		for (int j=0; j<a; j++){
			s = s + c;
		}
	}
	for (int i = s.size()-1; i>=0; i--){
		s_fan = s_fan + s[i];
	}
	
	long long t=s.size();
	if (is_huiwen(s, s_fan)){
		for (int i=0; i<=s.size()-1; i++){
			if(s[i]-s_fan[i] == 0){
				t -= 1;
			}
			
		}
		cout << t/2;
	} else{
		cout << 0;
	} 
	
	return 0;
}
