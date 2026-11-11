#include<bits/stdc++.h> 
using namespace std;
#define int long long
string s;
int ans;
signed main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int a;
	cin>>a;
	while(a--){
		int aa;
		string ss;
		cin>>aa>>ss;
		while(aa--){
			s+=ss;
		}
	}
	int len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
