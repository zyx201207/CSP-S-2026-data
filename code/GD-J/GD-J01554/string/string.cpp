#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[200005],ans;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i]>>s[i];
	ll i=1,j=1;
	while(i<n-j+1){
		if(a[i]<a[n-j+1]){
			if(s[i]!=s[n-j+1]) ans+=a[i];
			a[n-j+1]-=a[i];
			i++;
		}else if(a[i]>a[n-j+1]){
			if(s[i]!=s[n-j+1]) ans+=a[n-j+1];
			a[i]-=a[n-j+1];
			j++;
		}else{
			if(s[i]!=s[n-j+1]) ans+=a[n-j+1];
			i++;
			j++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
    return 0;
}
