#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200010],ans=0,b[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=a[i];
	}
	for(ll i=1,j=n;i<=j;){
		if(c[i]!=c[j]){
			if(b[i]>b[j]) b[i]-=b[j],ans+=b[j],j--;
			else b[j]-=b[i],ans+=b[i],i++;
		}
		else i++,j--;
	}
	cout<<ans<<endl;
	return 0;
}

