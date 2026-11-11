#include<bits/stdc++.h>
using namespace std;
long long const N = 5*1e5 +10;
long long n,m,ans=0;
long long a[N],b[N],c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		c[i]=a[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	if(m==0 || n==1){
		cout<<1;
		return 0;
	}
	//判断等差数列 
	bool fa=true;
	int x=a[2]-a[1];
	for(long long i=2;i<=n;i++){
		if(a[i]-a[i-1]!=x){
			fa=false;
			break;
		}
	}
	int t=1;
	if(fa){
		for(long long i=n-1;i>=1;i--){
			if(m<=0){
				break;
			}
			b[i]+=x*t;
			t++;
			m-=x*t;
		} 
		cout<<t;
		return 0;
	}
	
//	long long l=1,r=n;
//	while(l<=r){
//		long long mid=(l+r)/2;
//		bool fb=true;
	for(long long i=2;i<=n-1;i++){ 
		//当以c[i]为目标点
		long long cnt_in=0,mx=0;
		for(long long j=1;j<=i-1;j++){
			if(c[i-j]+m>=c[i]){
				m+=c[i-j];
				m-=c[i];
				c[i-j]=c[i];
				cnt_in++;
			}
			else{
				break;
			}
		}
		mx=max(mx,cnt_in);
		ans=mx;
	}
//	}
	cout<<ans;
	
	
	
	return 0;
} 
