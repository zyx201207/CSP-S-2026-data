//GZ-J00461 สตั้ศý ั๎ฯ่๎ฃ 
#include<bits/stdc++.h>
using namespace std;
long long t,cnt,x;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++) {
		cin>>x>>c;
		while(x--) s+=c;
	}
	long long l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]) cnt++;
		l++,r--;
	}
	cout<<cnt;
	return 0;
}
