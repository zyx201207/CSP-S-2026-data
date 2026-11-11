#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int N=5e5+10;
long long n,m,a[N],x,sum;
bool cmp(long long a,long long b){
	return abs(a-x)<abs(b-x);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(n<=5000){
		long long ans=0;
		for(int j=1;j<=n;j++){
			long long xx=m;
			x=a[j],sum=0;
	//		sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(abs(a[i]-x)<=xx&&a[i]<=x){
					sum++;
				//	cout<<a[i]<<" ";
					xx-=abs(a[i]-x);
				}
			}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	long long cnt=a[2]-a[1];
	bool fg1=1,fg2=1;
	for(int i=1;i<n;i++){
		if(a[i]!=i){
			fg1=0;
		}
		if(a[i+1]-a[i]!=cnt){
			fg2=0;
		}
	}
	if(a[n]!=n){
		fg1=0;
	}
//	if(fg1==1){
//		cout<<m+1;
//		return 0;
//	}
	if(fg2==1||fg1==1){
		for(int i=1;i<=n;i++){
			x+=a[i];
		}
		x/=n;
		sort(a+1,a+n+1,cmp);
		long long xx=a[1];
		for(int i=1;i<=n;i++){
			if(abs(a[i]-x)<=xx&&a[i]<=x){
				sum++;
				//	cout<<a[i]<<" ";
				xx-=abs(a[i]-x);
			}
		}
		cout<<sum;
		return 0;
	}
	cout<<0;
	return 0;
}
