#include <bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
int n,a[N],m,cnt;
char b[N];
string s;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
			m++;
		}
	}
	if(m%2==0){
		for(int i=0;i<=m/2-1;i++){
			if(s[i]!=s[m-i-1]) cnt++;
		}
	}else{
		for(int i=0;i<=m/2-1;i++){
			if(s[i]!=s[m-i-1]) cnt++;
		}
	}
	cout<<cnt;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	return 0;
}
