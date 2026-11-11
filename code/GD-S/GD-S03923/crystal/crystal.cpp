#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,d[N],sum1[N],sum2[N],res,a[N];
int ff(int x){
	int l=1,r=x,ans=x;
	while(l<=r){
		int mid=(l+r)/2;
//		cout<<mid<<" "<<sum1[x]-sum1[mid]-sum2[x]*(mid-1)+sum2[mid]*(mid-1)<<"\n";
		if(sum1[x]-sum1[mid]-sum2[x]*(mid-1)+sum2[mid]*(mid-1)<=m) ans=mid,r=mid-1;
		else l=mid+1; 
	}
	return ans;
}
void solve(int st){
	int ll=ff(st);
	//cout<<st<<" "<<ll<<"\n";
	res=max(res,st-ll+1);
}
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+(c-'0'),c=getchar();
	return x*f;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
		sum1[i]=sum1[i-1]+(i-1)*d[i];
		sum2[i]=sum2[i-1]+d[i];
	}
//	for(int i=1;i<=n;i++) cout<<sum1[i]<<" ";
//	cout<<"\n";
	for(int i=1;i<=n;i++){
		while(a[i]==a[i+1]&&i<=n) i++;
		solve(i);
	}
	cout<<res;
	return 0;
} 
