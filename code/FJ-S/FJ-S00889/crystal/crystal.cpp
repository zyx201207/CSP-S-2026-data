/*#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
int n;
long long m;
bool check(int id){
	long long cnt=0,num=a[id];
	for(int i=1;i<id;i++){
		//if(a[i]>=num) continue;
		cnt+=(long long)(num-a[i]);
	}
	return cnt<=m;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
//	map<long long,int> mp;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
//	long long s=0;
//	for(auto x:mp){
//		s+=x.second;
//		cout<<x.first<<" "<<x.second<<" "<<s<<"\n";
//	}
	int l=1,r=n,ans=0;
	while(l<=r){
		long long mid=(l+r)>>1;
		//cout<<mid<<' '<<a[mid]<<" "<<check(mid)<<"\n";
		if(check(mid)==1){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
//		cout<<s[i]<<" ";
	}
//	cout<<"\n";
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long l=1,r=i,k=0;
		while(l<=r){
			long long mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m){
				k=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		//cout<<i<<" "<<k<<" "<<(s[i]-s[k-1])<<"\n";
		ans=max(i-k+1,ans);
	} 
	cout<<ans;
	return 0;
} 
/*
10 2
-10 -10 -10 -9 -9 -8 -8 -8 -8 -8
*/
