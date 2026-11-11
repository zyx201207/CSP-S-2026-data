#include<bits/stdc++.h>
using namespace std;
string s;
int f(string s){
	int cnt=0;
	int len=s.size(); 
	for(int l=0,r=len-1;l<r;l++,r--){
		if(s[l]!=s[r]){
			cnt++;
		}
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char ch;
		scanf("%d %c",&x,&ch);
		for(int j=1;j<=x;j++){
			s.push_back(ch); 
		}
	}
	cout<<f(s);
	return 0;
} 
