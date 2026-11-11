#include<bits/stdc++.h>
using namespace std;
int n,a,ans;
char c;
string s="0";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	int l=(s.size()-1)/2,len=s.size()-1;
	for(int i=1;i<=l;i++){
		if(s[i]!=s[len+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

