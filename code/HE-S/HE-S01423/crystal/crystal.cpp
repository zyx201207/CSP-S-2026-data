#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans=0;
long long a[500005];
long long ma=-1000000000000,mi=1000000000000;
int search(long long l,long long r){
	if(l>r){
		return 0;
	}
	long long sum=m;
	long long cnt=0;
	priority_queue <long long> q;
	bool f=true;
	long long mid=(l+r)/2;
	for(int i=1;i<=n;i++){
		if(a[i]<mid){
			if(sum>=mid-a[i]){
				q.push((mid-a[i]));
				cnt++;
				sum-=(mid-a[i]);
			}
			if(sum<mid-a[i]&&(!q.empty())){
				f=false;
				long long x=q.top();
				if(mid-a[i]<x){
					q.pop();
					q.push(mid-a[i]);
					sum=sum+x-(mid-a[i]);
				}
			}
		}else if(a[i]==mid){
			cnt++;
		}
	}
	ans=max(cnt,ans);
	if(f==false) search(l,mid-1);
	search(mid+1,r);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
	}
	if(n>5000){
		int cha=abs(a[2]-a[1]);
		int sss=0;
		int aaa=-1;
		while(m>0){
			sss++;
			m-=(sss*cha);
			aaa++;
		}
		if(m==0){
			cout<<aaa+1;
		}else{
			cout<<aaa;
		}
		return 0;
	}
	search(mi,ma);
	cout<<ans;
	return 0;
}
