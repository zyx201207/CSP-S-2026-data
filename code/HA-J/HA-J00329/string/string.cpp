#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+5;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[N],m=0,ans=0;
	string b[N];
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	if(n%2!=0)m=n/2+1;
	else m=n/2;
	for(int i=1;i<=m;i++){
		if(m%2==0){
			if(b[i]!=b[n+1-i])ans+=min(a[i],a[n+1-i]);
		}
	}
	cout<<ans;
	return 0;
}