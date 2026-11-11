#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freoprn("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long T;
	cin>>T;
	while(T--){
		long long n;
		char m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			s+=m;
		}
	}		
	long long l=0,r=s.size()-1;
	long long cnt=0;
	while(l<r){
		if(s[l]==s[r]){
			l++;
			r--;
		}else{
			cnt++;
			l++;
			r--;
		}		
	}
	cout<<cnt;
	return 0;
}
