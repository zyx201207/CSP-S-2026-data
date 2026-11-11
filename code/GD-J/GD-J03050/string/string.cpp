#include <bits/stdc++.h> 
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int c;string b;
		cin>>c;
		cin>>b;
		for(int j=1;j<=c;j++){
			s+=b;
		}
	}
	int cnt=0;
	int len =s.size()-1;
	for(int i=0;i<=len;i++){
		if(s[i]!=s[len-i]){
			s[i]=s[len-i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
