#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,_;
ll a[N];
ll sum[N],num[N],hou[N];
ll k,ans;
//inline void read(int &n){
//	int x=0,f=1;
//	char c=getchar();
//	while(c<'0'||c>'9'){
//		if(c=='-')f=-1;
//		c=getchar();
//	}
//	while(c>='0'&&c<='9'){
//		x=(x<<1)+(x<<3)+(c^'0');
//		c=getchar();
//	}
//	n=x*f;
//} 
void init(){
	for(int i=1;i<=n;i++){
		sum[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		num[i]=num[i-1]+sum[i]*(i-1);
	}
//	for(int i=n;i>=0;i--){
//		hou[i]=hou[i+1]+sum[i];
//	}
//	for(int i=1;i<=n;i++){
//		cout<<"i="<<i<<' '<<"fa"<<num[i]<<' ';
//	}
} 
bool check(int p){
	ll tot=0ll;
//	cout<<"p="<<p<<'\n'<<'\n';
	for(int i=1;i<=n-p+1;i++){
		tot=num[i+p-1]-((a[i+p-1]-a[i])*(i-1))-num[i-1];//num sum
//		cout<<"i="<<i<<' '<<tot<<' '<<minn<<'\n';
		//minn=min(tot,minn);//if(p==315275)cout<<tot<<' '<<' ';
		if(tot<=k)return true;
	}
//	for(int i=1;i<=n-p+1;i++){
//		int opt=i+p-1;
//		tot=0ll;
//		for(int l=1;l<=p;l++){
//			tot+=a[opt]-a[i+l-1];
//		}
////		cout<<tot<<' ';
//		if(tot<=k)return true;
//	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	init();
	int l=0,r=n;
//	if(check(315275))cout<<"sgyr";
	while(l<=r){
		int mid=(l+r+1)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
