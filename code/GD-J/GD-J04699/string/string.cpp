#include <bits/stdc++.h>
using namespace std;
int n;
long long a;
char c;
string s;
long long ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","l",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
			
		}			
	}
	for(int i=(s.length()-1)/2;i>=0;i--){
		if(s[s.length()-1-i] != s[i]){
			ans++;
		}
	}	 
	
	cout<<ans;

	return 0;
}
