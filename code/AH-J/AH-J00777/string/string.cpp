#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct stu{
	long long x;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s=" ";
	long long n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		for(int j=1;j<=a[i].x;j++) s+=a[i].c;
	}
	long long len=s.size()-1;
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len-i+1]) cnt++;
	}
	cout<<cnt;
	return 0;
}
