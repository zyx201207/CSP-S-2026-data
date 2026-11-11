#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
using namespace std;
long long n,len,t1,t2,ans;
string s;
int main(){

	freopen("string5.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;char y;cin>>x>>y;
		for(int i=1;i<=x;i++){
			s+=y;
		}
		len+=x;
	}
	//string s1=s.substr(0,len/2),s2=s.substr(len/2+len%2+1);
	//cout<<s;
	for(int i=0,j=s.length()-1;i<j;i++,j--){
		if(s[i]!=s[j]){ans++;}
	}
	cout<<ans;
	return 0;
}
