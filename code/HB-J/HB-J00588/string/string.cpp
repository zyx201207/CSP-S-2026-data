#include<bits/stdc++.h>
using namespace std;
long long t,sum;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		long long n;
		string str;
		cin>>n>>str;
		for(long long i=1;i<=n;i++){
			s+=str;
		}
	}
	long long l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]){sum++;}
		l++;r--;
	}
	cout<<sum;
	return 0;
}
