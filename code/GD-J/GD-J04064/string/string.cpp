#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a,ans;
char c;
bool hw(string x){
	string y=x;
	reverse(x.begin(),x.end());
	return x==y?1:0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	if(hw(s)){
		cout<<0;
		return 0;
	}
	int l=s.size();
	for(int i=0;i<l;i++){
		if(hw(s)){
			break;
		}
		else if(s[i]==s[l+1-i]){
			continue;
		}
		s[l-1-i]=s[i];
		ans++;
	}
	cout<<ans;
	return 0;

}
