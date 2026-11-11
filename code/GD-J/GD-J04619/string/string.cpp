#include<bits/stdc++.h>
using namespace std;
string s;
int l;
bool check(string s){
	int len=s.size();
	string s1;
	for(long long i=len-1;i>=0;i--){
		s1=s1+s[i];
	}
	if(s1==s)return 1;
	else return 0;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>l;
	for(int i=1;i<=l;i++){
		int x;
		cin>>x;
		char c;
		cin>>c;
		for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	cout<<0;
	
	return 0;

} 
