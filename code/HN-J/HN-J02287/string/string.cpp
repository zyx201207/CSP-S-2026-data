#include<iostream>

using std::cin;
using std::cout;
int n,cnt;
std::string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	for(size_t i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
}
