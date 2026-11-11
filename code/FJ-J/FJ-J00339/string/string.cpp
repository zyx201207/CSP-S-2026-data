#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans=0;
char c[200005];
void bj(int i){
	if(i==n/2+1){
		cout<<ans;
		return;
	}
	if(c[i]!=c[n+1-i]){
	    if(a[i]<=a[n+1-i]){
			ans+=a[i];a[n+1-i]-=a[i];
			return bj(i+1);
		}
		else{
			ans+=a[n+1-i];a[i]-=a[n+1-i];n--;
			return bj(i);
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	bj(1);
	return 0;
}