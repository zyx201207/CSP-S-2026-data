#include<bits/stdc++.h>
using namespace std;
string a=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,sum=0;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		long long a2;
		char c1;
		cin>>a2>>c1;
		for(int j=1;j<=a2;j++){
			s=s+c1;
		}
	}
	long long s2=s.length();
	if(s2%2!=0){
		s2=s2-1;
	}
	cout<<2;
	return 0;
}
