#include<bits/stdc++.h>
using namespace std;
string s;
int huiwen(string s){
	int a,b,cnt=0;
	string s1,s2;
	a=0;
	b=s.size()-1;
	for(int i=1;i<=s.size()/2+1;i++){
		if(s[a]!=s[b]){
			cnt+=1;
		}
	}
	if(cnt==0){
		return 0;
	}
	return cnt-1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int num;
	char zifu;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cin>>num;
		cin>>zifu;
		for(int j=1;j<=num;j++){
			s+=zifu;
		}
	}
	cnt=cnt+huiwen(s);
	cout<<cnt;
	return 0;
}
