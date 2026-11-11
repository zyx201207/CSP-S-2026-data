#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5;
long long a[N+5],n,m;
bool check(int val){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]>val) break;
		cnt+=val-a[i];
	}
	if(cnt<=m) return true;
	else return false;
}
long long half(int l,int r){
	int mid;
	while(l<=r){
		mid=(r+l)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	if(check(r)) return r;
	else return -1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long minn=1e12+5,maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
	}
	long long res=half(minn,maxn);
	if(res==-1){
		cout<<0;
	}else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]>res) break;
			cnt++;
		}
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
