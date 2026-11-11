#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,ans=0,cnt=0;
	string s1,s2,b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		cnt=cnt+a;
		for(int j=a;j>=1;j--){
			s1+=b;
			s2=b+s2;
		}
	}
	for(int i=0;i<cnt;i++){
		if(s1[i]==s2[i]) continue;
		else ans++;
	}
	cout<<ans/2;
	return 0;
}
