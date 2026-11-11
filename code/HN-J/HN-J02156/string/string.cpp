#include<bits/stdc++.h>
using namespace std;
long long n,a,ans,cnt=1,x=cnt/2;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s[cnt]=c;
			cnt++;
		}
	}
	for(long long j=1;j<=x;j++){
		if(s[j]=s[x-1]){
			ans++;
		}
	}
	cout<<ans-1;
	return 0;
}
