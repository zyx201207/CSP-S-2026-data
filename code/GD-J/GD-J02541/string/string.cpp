#include<bits/stdc++.h>
using namespace std;
string s;
long long check(string s){
	long long cnt=0;
	int l=s.size();
	for(int i=0,j=l-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
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
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	cout<<check(s);
	return 0;
} 
