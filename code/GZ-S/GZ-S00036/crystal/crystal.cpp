#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,num,ans,total;
long long m,a[500002],sum[500001],tmp,prenum[500001];
struct sb{
	long long val;
	int cnt;
};
vector<sb> v;
bool flag1;
void erfen(int i){
	int l=1,r=i-1,mid;
	long long total=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(m>=(long long)v[i].val*(prenum[i]-prenum[mid-1])-sum[i]+sum[mid-1]){
			total+=prenum[i]-prenum[mid-1];
			if(mid>1){
			total+=min((long long)v[mid-1].cnt,(m+v[i].val*(prenum[mid-1]-prenum[i])+sum[i]-sum[mid-1])/(v[i].val-v[mid-1].val));
			}
			ans=max((long long)ans,total);
			total=0;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[n+1]=(long long)1e12+1;
	v.push_back((sb){0,0});
	for(int i=1;i<=n;++i){
		++num;
		if(a[i]!=a[i+1]){
			v.push_back((sb){a[i],num});
			num=0;
		}
		a[i]=0;
	}
	for(int i=1;i<v.size();++i){
		sum[i]=sum[i-1]+(long long)v[i].cnt*v[i].val;
		prenum[i]=prenum[i-1]+v[i].cnt;
		ans=max(ans,v[i].cnt);
	}
	for(int i=1;i<v.size();++i){
		erfen(i);
	}
	cout<<ans;
	return 0;
}
