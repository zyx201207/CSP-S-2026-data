//GZ-J00583 张钰博 北京师范大学贵阳附属中学 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	long long cnt=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++) s+=c;
	}
	for(long long i=s.size()/2+1;i<=s.size();i++){
		if(s[i]!=s[s.size()+1-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
