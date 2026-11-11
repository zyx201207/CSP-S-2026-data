#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int n,high,lth,ans;
ll m,a[500005],nowm; 

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	
	sort(a+1,a+1+n);
	
	high=n,lth=1;
	
	for(int i=n-1;i>0;i--){
		
		nowm+=a[high]-a[i];
		
		if(nowm>m){
			nowm-=(high-i)*(a[high]-a[high-1]);
			ans=max(ans,lth);
			high--,lth--;
		}
		
		lth++;
	}ans=max(ans,lth);
	
	cout<<ans;
	
	return 0;
}
