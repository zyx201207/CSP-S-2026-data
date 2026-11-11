#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,num[N],cnt,ans,l=1,r=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num+1,num+1+n);
	while(l<=r&&r<=n){
		while(cnt+(num[r+1]-num[r])*(r-l+1)<=m&&r<=n){
			cnt+=(num[r+1]-num[r])*(r-l+1);
			r++;
		}
		if(r-l+1>ans) ans=r-l+1;
		cnt+=(num[r+1]-num[r])*(r-l+1);
		r++;
		while(cnt>m){
			cnt-=(num[r]-num[l]);
			l++;
		}
	}
	cout<<ans;
	return 0;
}
