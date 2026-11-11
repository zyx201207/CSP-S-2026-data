#include<bits/stdc++.h>
using namespace std;
int n,ed=0;
long long m,ans=0,mx=1,ma=1;
long long a[500007];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++){
		ans+=mx*(a[i]-a[i-1]); 
		mx++;
		while(ans>m){
			ans-=a[i]-a[ed];
			ed++;
			mx--;
		}
		ma=max(ma,mx);
	}
	cout<<ma;
	return 0;
}
