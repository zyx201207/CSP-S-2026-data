#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long n,a[N],len,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld ",&a[i]);
		char c;
		cin>>c;
		for(long long j=1;j<=a[i];j++){
			s+=c;
		}
		len+=a[i];
	}
//	cout<<s<<endl;
	for(long long i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
//		cout<<s[i]<<" "<<s[len-i-1]<<endl;
		}
	}
	printf("%lld",ans);
	return 0;
}/*
2 
2 a 
3 a */
