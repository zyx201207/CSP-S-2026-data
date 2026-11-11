#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
long long n,ans=0,a[maxn],c[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>a[i]>>s;
		//a[i]+=a[i-1];
		c[i]=s[0]-'a'+1;
		//cout<<c[i]<<" ";
	}
	for(int i=1;i<=n/2;i++){
		long long j=n-i+1;
		if(a[i]==a[j]&&c[i]==c[j]) continue;
		if(a[i]==a[j]){
			ans+=a[i];
			continue;
		}
		long long m;
		if(a[i]>a[j]){
			m=a[i]-a[j];
			if(c[i]!=c[j]) ans+=a[j];
			for(int k=j-1;k>i;k--){
				if(a[k]>=m){
					a[k]-=m;
					if(c[k]!=c[i]) ans+=m;
					break;
				}
				else{
					m-=a[k];
					if(c[k]!=c[i]) ans+=a[k];
					a[k]=0;
				}
			}
		}
		else{
			m=a[j]-a[i];
			if(c[i]!=c[j]) ans+=a[i];
			for(int k=i+1;k<j;k++){
				if(a[k]>=m){
					a[k]-=m;
					if(c[k]!=c[j]) ans+=m;
					break;
				}
				else{
					m-=a[k];
					if(c[k]!=c[j]) ans+=a[k];
					a[k]=0;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
