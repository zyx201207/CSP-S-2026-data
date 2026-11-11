#include<bits/stdc++.h>
using namespace std;
unsigned long long n,sum,st,ed,ans,a[2000005];
char s[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)	cin>>a[i]>>s[i];
	st=1,ed=n;
	while(st<ed){
		if(s[st]!=s[ed]){
			if(a[st]>=a[ed]){
				ans+=a[ed];
				a[st]=a[st]-a[ed];
				ed--;
			}
			else{
				ans+=a[st];
				a[ed]=a[ed]-a[st];
				st++;
			}
		}
		if(s[st]==s[ed]){
			if(a[st]>=a[ed]){
				a[st]=a[st]-a[ed];
				ed--;
			}
			else{
				a[ed]=a[ed]-a[st];
				st++;
			}
		}
	}
	cout<<ans;
	return 0;
}