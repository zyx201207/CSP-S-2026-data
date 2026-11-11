#include<iostream>
using namespace std;

int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int n,cnt=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int c;
		char c1;
		cin>>c>>c1;
		for(int j=1;j<=c;j++){
			s+=c1;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
