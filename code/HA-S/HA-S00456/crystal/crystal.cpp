#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans,s[N];
int check(int l,int r){
	int sum=s[r]-s[l-1],need=a[l]*(r-l+1)-sum;
	if(m>=need)return 1;
	else return 0;
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		
	}

	for(int i=1;i<=n;i++){
		int l=i,r=n;
		
		while(l<r){
			
			int mid=l+r+1>>1;
			if(check(i,mid)){
				l=mid;
			}
			else r=mid-1;
		
		}
		ans=max(ans,r-i+1);

	}
	

	cout<<ans;
/*
5 8
-3 -1 2 2 7

*/
}