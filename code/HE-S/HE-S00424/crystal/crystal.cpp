#include<bits/stdc++.h>
using namespace std;
long long a[500010],n,m,sum,fow=0;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("crystal1.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sum/=n;
	sort(a+1,a+n+1);
	long long cnt=INT_MAX,lom;
	for(int i=1;i<=n;i++){
		if(sum-a[i]<=cnt&&a[i]<=sum){
			cnt=sum-a[i];
			lom=a[i];
			continue;
		}
		if(a[i]-sum<=cnt){
			cnt=a[i]-sum;
			lom=a[i];
		}
	}
	sort(a+1,a+n+1,cmp);
	long long total=0;
	for(int i=1;i<=n;i++){
		if(a[i]>lom){
			continue;
		}
		if(m>=total+(lom-a[i])){
			total=lom-a[i];
			fow++;
		}
	}
	cout<<fow;
	return 0;
}
