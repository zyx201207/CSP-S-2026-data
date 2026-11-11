#include<iostream>
#include<utility>
#include<algorithm>
#define int long long
using namespace std;
pair<int,char> a[200005];
int sum[200005],n;
inline int get(int x){
	return lower_bound(sum+1,sum+n+1,x)-sum;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		sum[i]=sum[i-1]+a[i].first;
	}
	int mid=lower_bound(sum+1,sum+n+1,sum[n]/2)-sum,lmid=sum[mid-1];
	int j=0;
	for(int i=n;i>mid;i--){
		if(sum[n]-sum[i-1]<=sum[get(j)]){
			if(a[get(j)].second!=a[i].second) ans+=sum[n]-sum[i-1]-j;
			j=sum[n]-sum[i-1];
		}
		else{
			if(a[get(j)].second!=a[i].second) ans+=sum[get(j)]-j;
			j=sum[get(j)];
			while(sum[get(j)+1]<=sum[n]-sum[i-1]){
				if(a[get(j)+1].second!=a[i].second) ans+=sum[get(j)+1]-j;
				j=sum[get(j)+1];
			}
			if(j<sum[n]-sum[i-1]){
				if(a[get(j)].second!=a[i].second) ans+=sum[n]-sum[i-1]-j;
				j=sum[n]-sum[i-1];
			}
		}
	}
	//cout<<j;
//	cout<<ans<<" ";
	if(j<lmid){
		if(lmid<=sum[get(j)]){
			if(a[get(j)].second!=a[mid].second) ans+=lmid-j;
			j=lmid;
		}
		else{
			if(a[get(j)].second!=a[mid].second){
				ans+=sum[get(j)]-j;
			} 
			j=sum[get(j)];
			while(sum[get(j)+1]<=lmid){
				if(a[get(j)+1].second!=a[mid].second) ans+=sum[get(j)+1]-j;
				j=sum[get(j)+1];
			}//cout<<get(j)+1;
			if(j<lmid){
				if(a[get(j)].second!=a[mid].second) ans+=lmid-j;
				j=lmid;
			}
		}
	}
	cout<<ans;
	return 0;
} 
