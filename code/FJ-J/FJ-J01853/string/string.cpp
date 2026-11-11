#include<bits/stdc++.h>
using namespace std;
string s;
char c;
long long n,a,cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	for(long long i=0;i<s.size();i++){
		cout<<s[i];
	}
	long long l=s.size()-1,i=0;
	while(i<l){
		if(s[i]!=s[l]){
			cnt++;
		}
		i++;
		l--; 
	}
	cout<<cnt;
	return 0;
}
