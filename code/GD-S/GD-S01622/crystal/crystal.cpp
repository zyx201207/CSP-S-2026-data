#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+8;
int n,m;
long long maxn=LLONG_MIN,ans=LLONG_MIN;
long long a[N];
vector<long long>id;
map<long long,long long> t;
long long solve(int l){
	int r=l+maxn-1,k=m;
	long long val=a[l];
	while(1){
		if(l==1&&r==n){
			return n;
		}
		if(l==1){
			k-=(r-l+1)*(a[r+1]-val);
			if(k<0){
				return r-l+1;
			}
			val=a[r+1];
			r+=t[val];
		}
		else if(r==n){
			k-=val-a[l-1];
			if(k<0){
				return r-l+1;
			}
			l--;
		}
		else{
			if(val-a[l-1]<(r-l+1)*(a[r+1]-val)){
				k-=val-a[l-1];
				if(k<0){
					return r-l+1;
				}
				l--;
			}
			else{
				k-=(r-l+1)*(val-a[r]);
				if(k<0){
					return r-l+1;
				}
				val=a[r+1];
				r+=t[val];
			}
		}
		if(k==0){
			return r-l+1;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
		if(t[a[i]]==maxn){
			id.push_back(a[i]);
		}
		else if(t[a[i]]>maxn){
			maxn=t[a[i]];
			id.clear();
			id.push_back(a[i]);
		}
	}
	sort(a+1,a+n+1);
	sort(id.begin(),id.end());
	int l=1,r=n;
	for(long long num:id){
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[mid]<num){
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		r=n;
		ans=max(ans,solve(l));
	}
	cout<<ans;
	return 0;
}
/*
10 8
1 1 3 4 4 5 6 6 7 8
4 4 4 4 4 5 6 6 7 8		1	5
1 1 6 6 6 6 6 6 7 8		4	6
1 1 3 4 7 7 7 7 7 8		6	5
*/
