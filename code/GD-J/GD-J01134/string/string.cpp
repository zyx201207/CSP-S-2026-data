#include<bits/stdc++.h>
using namespace std;
long long x,n,cnt=0,ans=0;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x>>c;
		cnt+=x;
		for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	for(long long i=0;i<cnt/2;i++){
		if(s[i]!=s[cnt-1-i])ans++;
	}
	cout<<ans;
	return 0;
}
