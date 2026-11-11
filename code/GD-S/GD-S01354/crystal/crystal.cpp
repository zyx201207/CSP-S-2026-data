#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500100];
int n,m;
bool cmp(int a,int b){
	return a<b;
}
bool pd(int s){
	int z=0;
	for(int i=1;i<=s;i++)z+=a[s]-a[i];
	if(z<=m)return 1;
	for(int i=2;i+s-1<=n;i++){
		z-=a[i+s-2]-a[i-1];
		z+=s*(a[i+s-1]-a[i+s-2]);
		if(z<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int l=1,r=n,mid;
	while(l<r){
		if((l+r)%2==0)mid=(l+r)/2;
		else mid=(l+r)/2+1;
		if(pd(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
		//cout<<mid<<endl;
	}
	cout<<l;
	
	return 0;
} 
