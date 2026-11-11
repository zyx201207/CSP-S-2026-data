#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n;
int a;
char c;
int num;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	for(int i=1;i<=s.size()/2;i++){
		if(s[i]!=s[n-i]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
