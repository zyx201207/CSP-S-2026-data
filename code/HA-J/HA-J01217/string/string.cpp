#include<bits/stdc++.h>
using namespace std;
int n;
long long a,ans;
char c;
string s1,s2;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s1+=c;
		}
	}
	s2=s1;
	reverse(s2.begin(),s2.end());
	for(int i=0;i<s1.size()/2;i++){
		if(s2[i]!=s1[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

