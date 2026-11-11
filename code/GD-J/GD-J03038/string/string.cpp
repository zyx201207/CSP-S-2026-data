#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,a,cnt=1,ans=0;
char c;
char b[1000000005];
stack<char>p;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		sum+=a;
		for(long long j=1;j<=a;j++){
			b[cnt]=c;
			cnt++;
			p.push(c);
		}
	}
	for(long long i=1;i<=sum/2;i++){
		if(b[i]!=p.top()){
			ans++;
		}
		p.pop();
	}
	cout<<ans;
	return 0;
} 
