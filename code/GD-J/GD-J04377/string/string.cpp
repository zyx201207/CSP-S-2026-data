#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,ans,a[N],len,sum[N][30];
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0') x=x*10+(c-'0'),c=getchar();
	return f*x;
}
struct node{
	int l,r;
	char val;
}b[N];
int ff(int x){
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(b[mid].l<=x) ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		char c;
		cin>>c;
		b[i]={len+1,len+a[i],c};
		for(int j=0;j<=25;j++){
			if(j==(c-'a')) continue;
			sum[i][j]=sum[i-1][j]+a[i];
		}
		len+=a[i];
	}
//	cout<<sum[6][0]<<" "<<sum[5][0]<<"\n";
	for(int i=1;i<=n;i++){
		if(b[i].l>len/2) break;
		int rr=ff(len+1-min(b[i].l,len/2));
		int ll=ff(len+1-b[i].r);
		int sum1=0,sum2=0;
		if(b[rr].r>len+1-min(b[i].l,len/2)){
			sum1=sum[rr-1][(b[i].val-'a')];
			if(b[rr].val!=b[i].val)ans+=((len+1-min(b[i].l,len/2))-b[rr].l+1);
//			cout<<"p1\n";
		} 
		else sum1=sum[rr][(b[i].val-'a')];
		if(b[ll].l<len+1-b[i].r){
			sum2=sum[ll][(b[i].val-'a')];
			if(b[ll].val!=b[i].val)ans+=(b[ll].r-(len+1-b[i].r)+1);
//			cout<<"p2\n";
		} 
		else sum2=sum[ll-1][(b[i].val-'a')];
//		cout<<sum2<<" "<<sum1<<" "<<ll<<" "<<rr<<" "<<ans<<"\n";
		if(sum1-sum2<=0) continue;
		ans+=(sum1-sum2);
	}
	cout<<ans;
	return 0;
} 
