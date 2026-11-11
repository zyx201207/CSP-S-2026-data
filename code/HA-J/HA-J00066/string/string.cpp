#include<bits/stdc++.h>
using namespace std;
int n,a,ans;
char c;
string s;
bool hw(string x){
	int i=0,j=x.size()-1;
	while(i<j){
		if(x[i]!=s[j]) return 0;
		i++;
		j--;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(int i=0;i<a;i++){
			s+=c;
		}
	}
	if(hw(s)){
		cout<<ans;
		return 0;
	}
	for(int i=0;i<s.size()/2;i++){
		int k=s.size()-i;
		if(s[i]!=s[k]){
			ans++;
			s[i]=s[k];
		}
	}
	cout<<ans;
	return 0;  
}
