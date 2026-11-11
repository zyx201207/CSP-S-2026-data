#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n;
	while(n--){
		long long t;
		string s1;
		cin >> t >> s1;
		while(t--) s+=s1;
	}
	long long ans=0,i=0,j=s.size()-1;
	while(i<j){
		if(s[i]!=s[j]) ans++;
		i++;
		j--;
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
