#include<bits/stdc++.h>
using namespace std;
long long n,cnt,cnt1;
string s,s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cnt1++;
		long long m;
		cin>>m;
		char c;
		cin>>c;
		for(long long i=1;i<=m;i++){
			s+=c;
		}
	}
	s1=s;
	reverse(s.begin(),s.end());
	s2=s;
	long long len=s.size();
	for(long long i=0;i<len/2;i++){
		if(s1[i]!=s2[i]){
			cnt++;
		}
	}
	cout<<cnt;
}
