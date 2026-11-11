#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500020],mid_id,mid;
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(n%2!=0){
		mid_id=n/2+1;
	}
	else{
		mid_id=n/2;
	}
	long long mid=a[mid_id],cnt=0;
	for(int i=mid_id;i>=1;i--){
		if(mid-a[i]<=m){
			m-=(mid-a[i]);
			cnt++;
		}
		else{
			break;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
