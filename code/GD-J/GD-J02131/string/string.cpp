#include<iostream>
#include<string>
using namespace std;
string s;
int n;
int ans;
int num;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>num>>c;
		s+=string(num,c);
	}
	string left;
	string right;
	for(int i=0;i<s.size()/2;i++){
		left+=s[i];
	}
	for(int i=(s.size()+1)/2;i<s.size();i++){
		right+=s[i];
	}
	for(int i=0;i<left.size();i++){
		if(left[i]!=right[i])ans++;
	}
	cout<<ans;
	return 0;
}
