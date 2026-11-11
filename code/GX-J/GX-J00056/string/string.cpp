#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[1000005]={},l=0;
	cin>>n;
	char c[1000005]={};
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	long long ans=0,x1=1,xt=n;
	for(long long i=1;i<=l/2;i++){
		if(c[x1]!=c[xt]){
			ans+=min(a[x1],a[xt]);
		}
		if(a[x1]==a[xt])a[x1]=a[xt]=0;
		else if(a[x1]>a[xt]){
				a[x1]-=a[xt];
				a[xt]=0;
			}
		else{
				a[xt]-=a[x1];
				a[x1]=0;
			}
		if(a[x1]==0)x1++;
		if(a[xt]==0)xt--;
		i+=min(a[x1],a[xt])-1;
	}
	cout<<ans;
	
	return 0;
}
