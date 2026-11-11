#include<bits/stdc++.h>
using namespace std;
string s,s1;
int a,n;
long long ans;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	s1+='!';
	int len=s.size();
	for(int i=1;i<=len;i++){
		s1+=s[i-1];
	}
	for(int i=1;i<=(len+1)/2;i++){
		if(s1[i]!=s1[len-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
