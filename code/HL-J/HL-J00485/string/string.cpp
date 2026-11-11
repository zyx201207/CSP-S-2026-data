#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],ans,sum;
char s[N];
string st;

void solve(){
	long long l,r;
	if(sum%2==1)l=sum/2,r=sum/2+2;
	else sum=n/2,r=sum/2+1;
	for(l,r;l>=1;l--,r++){
		if(l!=r)ans++;
	}
	cout<<ans;
	
}
int main(){
  	freopen("string.in","r",stdin);
  	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>s[i];sum+=a[i];
		for(long long j=1;j<=a[i];j++){
			st+=s[i];
		}
	}
	solve();
	return 0;
}

