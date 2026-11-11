#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;++i){
		int a;
		char c;
		cin>>a>>c;
		while(a--){
			s.push_back(c);
		}
	}
	string st = s;
	reverse(st.begin(),st.end());
	if(s == st){
		cout<<0;
	}
	else cout<<2;
	return 0;
}
