#include <bits/stdc++.h>

using namespace std;
long long n;
string s;
long long a;
char c;
stack <char> hw;
long long ans = 0;
int main(){
	cin.tie(0);
	cout.tie(0);
	std::ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i = 1;i<=n;i++){
		cin>>a>>c;
		for(long long j = 1;j<=a;j++){
			s+=c;
		}
	}
	if(s.size() % 2 == 1){
		for(long long i = 0;i<= s.size() - 1;i++){
			if(i == s.size()/2){
				continue;
			}
			else if(i < s.size() / 2){
				hw.push(s[i]);
			}
			else{
				if(hw.top() != s[i]){
					ans++;
				}
			}
		}		
	}
	else{
		for(long long i = 0;i<= s.size() - 1;i++){
			if(i < s.size() / 2){
				hw.push(s[i]);
			}
			else{
				if(hw.top() != s[i]){
					ans++;
				}
			}
		}		
	}
	cout<<ans;
	return 0;
}
