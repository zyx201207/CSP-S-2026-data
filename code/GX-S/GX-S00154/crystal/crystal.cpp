#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
using namespace std;
long long n,m,a[500005],s[500005],ans,mi=1e12+10;
bool check(int k){
	long long sum=0;
	for(int i=k;i<=n;i++){
		sum=((i-1)*a[i]-s[i-1])-((i-k)*a[i]-s[i-k]);
		//cout<<sum<<" ";
		if(sum<=m)return true;
	}
	return false;//1 3 5 8 10
}
int main(){

	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	 
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];mi=min(mi,a[i]);}
	for(int i=1;i<=n;i++){a[i]+=abs(mi)+1;}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){s[i]=s[i-1]+a[i];}
	long long l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;//cout<<mid<<endl;
		if(check(mid)){ans=mid;l=mid+1;}
		else r=mid-1;
	}
	cout<<ans;
}
