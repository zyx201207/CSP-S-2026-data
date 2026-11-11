#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s;
char c[N];
long long n,a[N],jis;
int hw(string ss){
	for(int i=0;i<=ss.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			jis++;
		}
	}
	return jis;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	cout<<hw(s)<<endl;
	return 0;
}
/*
3
 2 a
 2 b
 1 c
 6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
