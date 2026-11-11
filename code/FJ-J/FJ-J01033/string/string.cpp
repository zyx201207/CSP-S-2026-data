#include<bits/stdc++.h>
using namespace std;
string s;
long long len,mid,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long op;
	cin>>op;
	for(long long i=1;i<=op;i++){
		long long a;
		string c;
		cin>>a>>c;
		len+=a;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	mid=(len>>1)+1;
	for(long long i=0;i<mid;i++){
		if(s[i]!=s[op+1-i])ans++;
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
3
2 a
2 b
1 c
*/

