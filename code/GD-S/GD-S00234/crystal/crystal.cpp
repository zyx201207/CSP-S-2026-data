#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=5e5+10;
const int inf=0x3f3f3f3f;
long long n,m,a[N],ans,res;
bool check(long long mid){
	long long ma=a[mid];
	long long sum=0;
	for(int i=1;i<=mid;i++){
		sum+=ma-a[i];
		if(sum>m)  return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal3.in","r",stdin);
	freopen("crystal3.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+1+n);
	long long l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

