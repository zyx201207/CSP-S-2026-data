#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[514514],answ,zhui[514514],l,r;
bool cmp(int x,int y){
	return x<y;
}
bool shuijing(int x,int y){
	if(zhui[y]-zhui[x]-(x-1)*(a[y]-a[x])<=m)return 1;
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++)
	zhui[i]=zhui[i-1]+(i-1)*(a[i]-a[i-1]);
	answ=1;
	for(int i=2;i<=n;i++){
		l=1;r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(shuijing(mid,i)){
				answ=max(answ,i-mid+1);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
	}cout<<answ<<'\n';
	return 0;
} 
