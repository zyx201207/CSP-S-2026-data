#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,t[200010],a=0;
	string s;
	char s1[200010];
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>t[i]>>s1[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2&&s1[1]!=s1[2]){
		if(t[1]>=t[2]){
			cout<<t[2];
			return 0;
		}else {
			cout<<t[1];
			return 0;
		}
	}else if(n==2&&s1[1]==s1[2]){
		cout<<0;
	}
	return 0;
}
