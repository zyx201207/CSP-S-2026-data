#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct node{
	vector<long long>xs;
	void add(long long x){
		xs.push_back(x);
	}
	void build(){
		sort(xs.begin(),xs.end());
		xs.erase(unique(xs.begin(),xs.end()),xs.end());
	}
	long long id(long long x)const{
		return lower_bound(xs.begin(),xs.end(),x)-xs.begin()+1;
	}
	long long val(long long x)const{
		return xs[x-1];
	}
	long long size(){
		return xs.size();
	} 
};
node dc;
long long n,m,a[N],sum[N],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		dc.add(a[i]);
	}
	dc.build();
	for(int i=1;i<=n;i++)
		sum[dc.id(a[i])]++;
	for(int i=dc.size();i>=2;i--){
		long long num=sum[i],flag=m;
		for(int j=i-1;j>=1;j--){
			long long f=dc.val(i),s=dc.val(j);
			if(flag>=(f-s)*sum[j])
				num+=sum[j],flag-=(f-s)*sum[j];
			else{
				num+=flag/(f-s);
				flag-=(f-s)*(flag/(f-s));
				if(flag>0)
					flag=-1;
				break;
			}
		}
		ans=max(ans,num);
		if(flag>=0)
			break;
	}
	printf("%lld",ans);
	return 0;
} 
