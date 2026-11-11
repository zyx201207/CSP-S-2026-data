#include<bits/stdc++.h>
using namespace std;
const int N=2e5+6;
bool vis[N];
int a[N];
int ans[N];
int n,x,maxsum;
int pow_30[35]={0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431,67108863,134217727,268435455,536870911,1073741823};
void dfs(int step,int idx){
	if(step==x+1){
		int sum=ans[1];
		for(int i=2;i<=x;i++){
			sum&=ans[i];
		}
		maxsum=max(sum,maxsum);
	}
	for(int i=idx;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			ans[step]=a[i];
			//ans=ans&a[i];
			dfs(step+1,i);
			vis[i]=0;
			ans[step]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>x;
	int maxn=-1;
	int powcnt=0;
	int abs1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i-1) abs1++;
		for(int j=1;j<=30;j++){
			if(a[i]==pow_30[j]-1) powcnt++;
		}
		maxn=max(a[i],maxn);
	}
	if(n<=20){
		dfs(1,1);
		cout<<maxsum;
	}
	else if(x==1){
		cout<<maxn;
	}
	else if(x==n){
		int c=a[1];
		for(int i=2;i<=n;i++){
			c&=a[i];
		}
		cout<<c;
	}
	else if(x==2){
		int maxsum=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)
					maxsum=max((a[i]&a[j]),maxsum);
			}
		}
		cout<<maxsum;
	}
	else if(powcnt==n){
		sort(a+1,a+1+n);
		int ans=a[n];
		for(int i=n-1;i>=1;i--){
			ans&=a[i];
		}
		cout<<ans;
	}
	else if(abs1==n){
		for(int i=1;i<=18;i++){
			if(n==pow(2,i)){
				cout<<n-x;
				break;
			}
		}
	}
	return 0;
}
