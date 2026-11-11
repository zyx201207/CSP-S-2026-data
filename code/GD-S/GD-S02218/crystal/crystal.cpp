#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,cnt[N],a[N],last,maxx,sum[N];
bool check(int x,int y){
	int val=(y-x+1)*a[y];
	if(val-(cnt[y]-cnt[x-1])<=m) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cnt[i]=cnt[i-1]+a[i];
		sum[i]=i*a[i]-cnt[i-1];
//		cout<<sum[i]<<' ';
	}
//	cout<<'\n';
	for(int i=n;i>=1;i--){
		long long val=(i+1)*a[i]-m-cnt[i];
//		if(i==315275){
//			cout<<k<<" "<<m<<'\n';
//		}
        long long l=1,r=i;
        while(l<=r){
        	int mid=(l+r)/2; 
        	if(check(mid,i)) r=mid-1;
        	else l=mid+1;
		}
//		cout<<l<<" ";
		maxx=max(maxx,i-l+1);
	}
	cout<<maxx;
}//19883110
/*
5 5
1 2 4 8 9
*/
