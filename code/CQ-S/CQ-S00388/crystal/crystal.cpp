#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],n,m;
int s[N];
bool check(int x){
	for(int i=1;i+x-1<=n;i++){
		if(x*a[i+x-1]-(s[i+x-1]-s[i-1])<=m)return 1;
	}return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	while(l<r){
		int mid=l+r+1ll>>1;
		if(check(mid)){
			l=mid; 
		}else r=mid-1;
	}cout<<l;
	return 0;
} 
