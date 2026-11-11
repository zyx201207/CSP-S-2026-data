#include<bits/stdc++.h>
using namespace std;
string s;
int ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	s+=' ';
	while(n--){
		long long t;
		string c;
		cin>>t>>c;
		while(t--){
			s+=c;
		}
	}
	n=s.size()-1;
	for(int i=1,j=n;i<=j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
			s[i]=s[j];
		}
	}
	cout<<ans;
	return 0; 
}
