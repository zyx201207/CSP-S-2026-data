#include<bits/stdc++.h> 
using namespace std;
string s;
char b;
long long n,a,all,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s+=b;
		}
		all+=a;
	}
	for(int i=0;i<all/2;i++){
		if(s[i]!=s[all-i-1]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}//6 1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b
