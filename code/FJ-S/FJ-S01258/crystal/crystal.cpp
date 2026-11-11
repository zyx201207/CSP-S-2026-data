#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
map<long long,int>cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	bool t1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		if(a[i]!=i)t1=0;
	}
	sort(a+1,a+n+1);
	int len=unique(a+1,a+n+1)-a-1;
	if(t1){//a[i]==i
		int ans=1;
		long long i=1;
		while(ans<n&&m>=i){
			if(m-i<0)break;
			m-=i;
			ans++;
			i++;
		}
		cout<<ans<<endl;
		return 0;
	}
	bool t2=1;
	long long tsum=a[2]-a[1];
	for(int i=2;i<n;i++){
		if(a[i]+tsum!=a[i+1])t2=0;
	}
	if(t2){//a[i]为等差数列 
		int ans=1;
		long long i=abs(tsum);
		while(ans<n&&m>=i){
			if(m-i<0)break;
			m-=i;
			ans++;
			i+=abs(tsum);
		}
		cout<<ans<<endl;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=len;i++){//暴力 
		long long t=m;
		int sum=cnt[a[i]];
		for(int j=i-1;j>=1;j--){
			long long x=a[i]-a[j];
			long long c=cnt[a[j]];
			if(t>=x*c){
				t-=(x*c);
				sum+=c;
			}
			else{
				sum+=(t/x);
				t%=x;
				break;
			}
		}
		ans=max(ans,sum);
	} 
	cout<<ans<<endl;
	return 0;
} 
