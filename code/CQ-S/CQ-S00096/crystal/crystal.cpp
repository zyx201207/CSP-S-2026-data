#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+10; 
long long n,m,a[N],s[N],l[N];
bool check(long long ans,long long x){
	if(l[ans]-l[x+1]-(x-ans+1)*s[x]<=m) return 1;
	else return 0;
}
long long sreach(int x){
	long long l=1,r=x,ans=1;
	while(l<=r){
		long long mid=l+r>>1;
		if(check(mid,x)){
			ans=max(ans,x-mid+1);
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1); 
	for(int i=n-1;i>=1;i--){
		long long k=a[i+1]-a[i]; 
		s[i]=s[i+1]+k; 
	}
	long long ans=1;
	for(int i=n;i>=1;i--){
		l[i]=l[i+1]+s[i];
		//cout<<l[i]<<" ";
	}
	for(long long i=1;i<=n;i++){
		ans=max(ans,sreach(i));
	}
	cout<<ans;
	return 0; 
} 
