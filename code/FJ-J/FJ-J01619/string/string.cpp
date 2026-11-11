#include<bits/stdc++.h>
using namespace std;
string s1;
char a;
long long n,g,ge=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>g;
		cin>>a;
		ge+=g;
		for(int i=0;i<g;i++){
			s1+=a;
		}
	}
	for(int i=0;i<s1.size()/2;i++){
		if(s1[i]!=s1[ge-i-1]){
			s1[ge-i-1]=s1[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
