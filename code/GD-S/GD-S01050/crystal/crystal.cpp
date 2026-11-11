#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5+5;
int n,m,a[N];

bool check(int x){
	int sum=0;
	for(int i=x;i<=n;i++){
		for(int j=i-1;j>=i-x+1;j--){
			sum+=a[i]-a[j];
		}
		if(sum<=m)return 1;
		sum=0;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(l+1<r){
		int mid=(l+r)>>1;//ºÏ³Émid¸ö 
		if(check(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	cout<<l;
	return 0;
} 
