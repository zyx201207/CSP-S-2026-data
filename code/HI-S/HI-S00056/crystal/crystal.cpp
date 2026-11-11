#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],l=1e12+5,r=-1e12-5,mid,maxx=0;
bool cmp(long long u,long long v){
	return u>v;
} 
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);
	}

	sort(a+1,a+n+1,cmp);
	while(l<=r){
		mid=(l+r)/2;
		long long cnt=m,ent=0;
		for(int i=1;i<=n;i++){
			if(a[i]<=mid){
				if(cnt-(mid-a[i])>=0){
					ent++;
					
				}
				cnt=cnt-(mid-a[i]);
			}
		}
		if(cnt<0){
			
			r=mid-1;
			maxx=max(ent,maxx);
		}else if(cnt>0){
			l=mid+1;
			
			maxx=max(ent,maxx); 
		}else if(cnt==0){
			maxx=max(ent,maxx);
			cout<<maxx;
			return 0;
		}
	}
	cout<<maxx;
	return 0;
}
