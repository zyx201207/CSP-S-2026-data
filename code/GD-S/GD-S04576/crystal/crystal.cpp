#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=500050;
long long n;
unsigned long long m;
long long sum[MAXN];
long long a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long pd1=0,pd2=1;
	int cha1=0,cha2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		if(i==1||a[i]==a[i-1]) pd1++;
	}
	if(pd1==n){
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	/*
	cha1=a[2]-a[1];
	for(int i=2;i<=n;i++){
		cha2=a[i]-a[i-1];
		if(cha2==cha1) pd2++;
	}
	if(pd2==n){
		unsigned long long mm=m;
		int ans=1;
		for(int i=n-1;i>=1;i--){
			int cha=a[n]-a[i];
			if(mm>=cha) ans++,mm-=cha;
			else break;
		}
		cout<<ans;
		return 0;
	}
	*/
	/*
	int ans=1;
	for(int i=2;i<=n;i++){
		int ans1=1;
		unsigned long long mm=m;
		for(int j=i-1;j>=1;j--){
			long long cha=a[i]-a[j];
			if(mm>=cha)
				ans1++,mm-=cha;
			else break;
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	*/
	long long ans=1,len=0;
	long long ans1=0;
	for(int i=2;i<=n;i++){
		len++;
		long long cha=a[i]-a[i-1];
		long long bu=len*cha;
		ans1+=bu;
		while(ans1>m){
			ans1-=a[i];
			ans1+=a[i-len];
			len--;
		}
		ans=max(len+1,ans);
	}
	cout<<ans;
	return 0;
}
