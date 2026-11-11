#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[1000005],ans,m,sum=-1,n,maxn,ts,maxm,p,minn=0x3f3f3f3f;
void f(int i,int cnt){
	if(i==n+1&&cnt==m){
		if(cnt==m){
			ans=max(ans,sum);
		}
			return ;
	}
	f(i+1,cnt);
	if(sum==-1){
		sum=a[i];
	}
		int sum2=sum;
		sum&=a[i];
		f(i+1,cnt+1);
		sum=sum2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
		if(i==1){
			ts=a[i];
		}
		ts&=a[i];
	}
	if(n<=2000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					maxm=max(maxm,a[i]&a[j]);
				}
			}
		}
	}
	sort(a+1,a+n+1);
	if(n<=25){
		f(1,0);
		cout<<ans;
	}else{
		if(m==1){
			cout<<maxn;
		}else if(m==2){
			cout<<maxm;
		}else if(m==n){
			cout<<ts;
		}else if(a[1]==0&&a[2]==1&&a[3]==2){
			p=a[n];
			for(int i=n;i>=n-m+1;i--){
				p&=a[i];
			}
			cout<<p;
		}else if(maxn<2){
			cout<<minn;
		}else{
			cout<<a[n-m+1];
		}
	}
}
