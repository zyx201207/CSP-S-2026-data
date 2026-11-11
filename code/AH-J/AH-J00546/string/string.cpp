#include<bits/stdc++.h>
using namespace std;
long long n,t,mi;
char a;
string s,s1;
long long cha_q(string b,string b1){
	long long cnt;
	int h=b.size();
	for(int j=0;j<h;j++){
		if(b[j]!=b1[j]){cnt++;}
	}
	return cnt/2;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t>>a;
		while(t--) s+=a;
	}
	s1=s;
	reverse(s1.begin(),s1.end());
	if(s==s1){cout<<0;return 0;}
	mi=min(mi,cha_q(s,s1));
	cout<<mi;
	return 0;
}
