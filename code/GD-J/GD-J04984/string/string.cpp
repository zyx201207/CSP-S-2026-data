#include<bits/stdc++.h>
using namespace std;
struct str{
	long long num;
	string st;
	void input(){
		cin>>num>>st;
	}
}s[2*100005];
string s1;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		s[i].input();
		for(long long j=1;j<=s[i].num;j++){
			s1+=s[i].st;
		}
	}
	for(long long i=0;i<s1.size()/2;i++){
		if(s1[i]!=s1[s1.size()-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
