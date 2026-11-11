#include<bits/stdc++.h>
using namespace std;
int n,x;
char c;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>x>>c;
		for(int i=1;i<=x;i++){
			s+=c;
		}
	}
//	cout<<s;
	int len=s.size();
	int cnt=0;
	for(int i=0;i<len/2;i++){
		int p=len-i-1;
		if(s[i]!=s[p]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
