#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n,m;
int ans;
bool boost=1;
long long cha;
long long a[N];
bool solve(int x){
	int ans=0;
	for(int i=0;i<x;i++){
		ans+=a[x]-a[i];
		if(ans>m){
			return 1;
		}
	}
	return ans>m;
}
bool solve2(int x,int y){
	int ans=0;
	for(int i=x;i<y;i++){
		ans+=a[y]-a[i];
		if(ans>m){
			return 1;
		}
	}
	return ans>m;
}
int erfen(int l,int r){
	int mid=(l+r)/2;
	//cout<<mid<<endl;
	if(l==r){
		return mid;
	}
	if(solve(mid)){
		erfen(l,mid);
	}else{
		erfen(mid+1,r);
	}
}
int erfen2(int l,int r,int y){
	int mid=(l+r)/2;
	//cout<<mid<<endl;
	if(l==r){
		return y-mid+1;
	}
	if(solve2(mid,y)){
		erfen2(mid+1,r,y);
	}else{
		erfen2(l,mid,y);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i>=1){
			if(cha!=a[i]-a[i-1] and i>=2){
				boost=0;
			}	
			cha=a[i]-a[i-1];		
		}
	}
	if(boost){
		//cout<<111111<<endl;
		int cnt=1,idx=0;
		while(idx<=m and cnt<=n){
			idx+=idx+cha;
			cnt++;
		}
		cout<<cnt<<endl;
		return 0;
	}
	sort(a,a+n);
	int x=erfen(0,n);
	ans=x;
	//cout<<ans<<endl;
	for(int i=x+1;i<n;i++){
		ans=max(ans,erfen2(0,i,i));
	}
	cout<<ans<<endl;
	//cout<<erfen2(0,4,4);
	return 0;
}
