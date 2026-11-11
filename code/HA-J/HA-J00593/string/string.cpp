#include<bits/stdc++.h>
using namespace std;
#define long long int
int a,n,cnt = 0;
char c;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	for(int i = 0;i<s.size();i++){
		if(s[i] != s[s.size()-i-1]){
			s[s.size()-i-1] = s[i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
