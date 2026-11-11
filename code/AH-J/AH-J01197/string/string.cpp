#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e6+1;
ll x,n,cnt,a[N];
string s;
char c;
bool cmp(string c){
	string c2=c;
	reverse(c.begin(),c.end());
	return c2==c;
}
void sc(){
	ll len=s.size()/2;
	for(int i=0;i<=len;i++){
		if(cmp(s)){
			cout<<cnt;return;
		}else if(s[i]!=s[s.size()-i-1]){
			cnt++;
			s[i]=s[s.size()-i-1];
		}
	}
	cout<<cnt;
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>x>>c;
		while(x--)s+=c;
	}
	sc();
	return 0;
}
