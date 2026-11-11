#include<bits/stdc++.h>
using namespace std;
int n,a,ans;
string s,h;
char c;
int num(string x){
	for(int i=1;i<=s.size();i++){
		if(s[i]!=x[i]){
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s="";
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	h="";
	int len=s.size();
	for(int i=1;i<=(len+1)/2;i++){
		h=h+s[i];
	}
	for(int i=len/2;i>=1;i--){
		h+=s[i];
	}
	cout<<num(h);
	return 0;
} 



