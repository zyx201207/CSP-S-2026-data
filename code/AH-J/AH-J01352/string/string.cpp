#include<bits/stdc++.h>
using namespace std;
long long n;
long long a;
string s[10010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>s[i];
	}
	for(int i=0;i<n;i++){
		if(n==1){
			cout<<0;
		}
		if(s[i]==s[i-1]){
			cout<<0;
		}
	}
	return 0;
}
