#include<bits/stdc++.h>
using namespace std;
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	int n;
	cin>>n;
	string s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s+=b;
		}
	}
	int num=0;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]!=s[num]){
			cnt++;
		}
		num++;	 	
	}
	cout<<cnt/2;
	return 0;
}
