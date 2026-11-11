#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,len,ans,cnt;
long long a[N],b[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	long long hl=len/2+1;
	int j=n,i;
	for(i=1;i<=n;i++){
		if(cnt+a[i]>=hl) break;
		cnt+=a[i];
		long long s=0;
		while(s+a[j]<a[i]&&j>i+1){
			if(c[i]!=c[j]) ans+=a[j];
			s+=a[j],j--;
		}
		if(c[i]!=c[j]) ans+=a[i]-s;
		a[j]-=a[i]-s;
	}
	long long z=hl-1-cnt,y=cnt+a[i]-hl-(len%2)+1;
	if(z<y&&c[i-1]!=c[i]) ans+=y-z;
	else if(z>y&&c[i+1]!=c[i]) ans+=z-y;
	cout<<ans;
	return 0;
}
