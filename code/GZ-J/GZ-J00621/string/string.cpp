#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int s[N],sl,sr;long long a=0;long long n,lens,ans;char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s[lens+j]=c;
		}
		lens+=a;
	}
	for(long long i=1;i<=lens/2;i++){
			if(s[i]!=s[lens-i+1]) ans++;
		}
	cout<<ans;
	return 0;
}
