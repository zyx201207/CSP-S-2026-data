//GZ-J00437 张瑞晨 清华中学 
#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string s;
int hw(string s){
	int len=s.size();
	for(int i=1;i<=len/2;i++){
		if(s[i-1]!=s[len-i]){
			s[i-1]=s[len-i];
			cnt++;
		}
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		while(a){
			s+=c;
			a--;
		}
	}
	if(hw(s))cout<<cnt;
	return 0;
}
