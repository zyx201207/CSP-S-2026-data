#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="a";
	long long cnt=0,a,n,p,q,ans=0;
	char c;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++) s+=c;
		cnt+=a;
	}
	p=1,q=cnt;
	while(p<q){
		if(s[p]!=s[q]) ans++;
		p++;
		q--;
	}
	cout<<ans<<endl;
	return 0;
}
