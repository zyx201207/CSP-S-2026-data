//贵州师范大学贵安新区附属初级中学 刘炫希 GZ-J00121
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,l=0,ans=0;
	cin>>n;
	string s="";
	for (int i=1;i<=n;i++){
		int tmp;
		string ts;
		cin>>tmp>>ts;
		l+=tmp;
		for (int i=1;i<=tmp;i++){
			s+=ts;
		}
	}
	for (int i=0;i<=l/2;i++){
		if (s[i] != s[l-i-1]){
			ans++;
		}
	}

	cout <<ans;
	return 0;
}

