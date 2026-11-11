#include<bits/stdc++.h>
using namespace std;
long long n;
string s={},r={};
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1,v;i<=n;i++){
		cin>>v>>c;
		for(int j=1;j<=v;j++){
			s+=c;
		}
	}
	long long m;
	if(s.size()%2==0){
		m=s.size()/2;
	}else{
		m=s.size()-1;
		m=m/2;
	}
	for(long long i=m-1;i>=0;i--){
		r+=s[i];
	}
	long long num=0;
	if(s.size()%2==1){
		m+=1;
	}
	for(long long i=m;i<s.size();i++){
		if(r[i-m]!=s[i]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
