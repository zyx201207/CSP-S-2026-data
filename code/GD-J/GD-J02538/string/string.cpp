#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],c[200005];
int b[200005],d[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char k;
		cin>>a[i]>>k;
		c[i]=k-'a'+1;
		b[n+1-i]=a[i];
		d[n+1-i]=c[i];
	}
	int i=0,j=0,ans=0;
	int len1=0,len2=0;
	while(i<n||j<n){
		if(min(len1,len2)==len1){
			i++;
			ans+=(c[i]!=d[j])*min(abs(len2-len1),a[i]);
			len1+=a[i];
		}else {
			j++;
			ans+=(c[i]!=d[j])*min(b[j],abs(len1-len2));
			len2+=b[j];
		}
	}
	cout<<ans/2;
	return 0;
} 
