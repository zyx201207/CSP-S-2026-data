#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long n,m;
long long mx;
long long b[200010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
	long long len=1;
	long long now=0,ans=1,mxnum=0,k=2;
	for(int i=2;i<=n;i++){
		long long x=a[i]-a[i-1];
		if(now+x*len<=m){
			now+=x*len;
			mxnum+=x;
			len++;
			ans=max(ans,len);
			continue;
		}
		while(len>1&&now+x*len>m){
			now-=mxnum;
			mxnum-=a[k]-a[k-1];
			k++;
			len--;
			ans=max(ans,len);
		}
		if(now+x*len<=m){
			now+=x*len;
			mxnum+=x;
			len++;
			ans=max(ans,len);
			continue;
		}
		ans=max(ans,len);
	}
	cout<<ans;
	return 0;
}
//燃尽了，只有这题会写，希望能AC 
