/*
感觉像差分 
 不是差分，应该是双指针 
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5+10;

ll n,m;
ll a[N];
ll ans=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	ll sum=0,l=1;//目前可以的最左侧是l，然后要加入的是i 
	ans=1;
	for(int i=2;i<=n;i++){
		if(sum+(a[i]-a[i-1])*(i-l)<=m){
			sum+=(a[i]-a[i-1])*(i-l);
			ans=max(ans,(i-l+1)*1LL);
		}else{
			while(sum+(a[i]-a[i-1])*(i-l)>m && l<i){
				
				sum-=(a[i-1]-a[l]);
				l++;
			}
			sum+=(a[i]-a[i-1])*(i-l);
			ans=max(ans,(i-l+1)*1LL);
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

6 9
1 2 -3 7 5 -8
*/
