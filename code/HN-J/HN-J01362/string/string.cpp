#include<bits/stdc++.h>
using namespace std;
long long n;
long long a;
char b;
char c[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long k=1;
	long long len=0;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			c[k]=b;
			k++;
		}
		len+=a;
	}
//		a[k]=b[k];
//		len+=a[k];
//		if(c[i]==c[i-1]){
//			a[i-1]+=a[i];
//			k--;
//			continue;
//		}
//		b[k]+=b[k-1];
//		k++;
	
	long long sea;
	if(len%2==1)sea=len/2+1;
	else sea=len/2;
	long long ans=0;
	for(int i=1;i<=sea;i++){
		if(c[i]!=c[len-i+1])ans++;
	}
//	for(int i=1;i<=k;i++){
//		if(b[i-1]<=sea&&b[i]>=sea){
//			int l=b[i];
//			for(int j=1;j<=l;j++){
//				if(c[j]!=c[len-j+1]){
//					ans+=min(a[j],a[len-i+1]);
//					a[j]-=a[len-i+1]
//					if(a[j]>)
//				}
//			}
//		}
//	}
//	
	cout<<ans;
	return 0;
}

