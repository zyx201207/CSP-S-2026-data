#include <bits/stdc++.h> 
using namespace std;
long long n,m;
string s;
char a;
long long ans=0;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	cin>>n;
	while (n--){
		cin>>m>>a;
		for(int i=0;i<m;i++){
			s[i]=a;
		}
	}
	int m=1;
	for(int i=s.length()/2;i<=s.length();i++){
		if(s[i]!=s[s.length()/2-m])ans++;
		m++;
	}
	cout<<ans;
	return 0;
}
