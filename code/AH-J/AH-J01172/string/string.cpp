#include<bits/stdc++.h>
using namespace std;
const int N=0;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	string s;
	cin>>n;
	while(n--){
		int num;
		char ch;
		cin>>num>>ch;
		while(num--){
			s+=ch;
		}
	}
	ll a,ans=0,len=ll(s.size());
	for(int i=0;i<=len/2-1;i++){
		if(s[i]!=s[len-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
