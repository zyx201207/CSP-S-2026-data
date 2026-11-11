#include<bits/stdc++.h>
using namespace std;
string s;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	long long n,m,cnt=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m>>a;
		for(long long j=1;j<=m;j++){
			s+=a;
		}
	}
	long long l=s.size();
	if(l%2==0){
		for(long long i=0;i<l/2;i++){
			if(s[i]!=s[l-i-1]){
				cnt++;
			}
		}
	}else{
		for(long long i=0;i<l/2+1;i++){
			if(s[i]!=s[l-i-1]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
