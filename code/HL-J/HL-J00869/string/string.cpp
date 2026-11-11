#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x,num;
char y;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		for(int i=1;i<=x;i++){
			s+=y;
		}
	}
	string s1,s2;
	s1=s2=s;
	reverse(s1.begin(),s1.end());
	if(s1==s2){
		cout<<0;
		return 0;
	}
	for(int i=0;i<=s.size()/2-1;i++){
		if(s[i]!=s[s.size()-1-i]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
