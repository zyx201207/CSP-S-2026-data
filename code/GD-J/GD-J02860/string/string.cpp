#include<bits/stdc++.h>
using namespace std;
#define t long long
t n,a;
char c[200009];
string s;
t ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(t i=1;i<=n;i++){
		cin>>a>>c[i];
		for(t j=1;j<=a;j++){
			s+=c[i];
		}
	}
	t pp=s.size();
	t j=pp-1;
	for(t i=0;i<pp/2;i++){
		j--;
		if (s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
} 
