#include<bits/stdc++.h>
using namespace std;
string s;
int n;
long long h,ans=0,m=0;
char a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h>>a;
		for(int j=1;j<=h;j++){
			s+=a;
		}
	}
	
	m=s.size();
	
	for(long long i=0;i<(m>>1);i++){
		if(s[i]!=s[m-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
