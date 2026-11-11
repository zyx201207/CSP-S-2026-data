/*
% hZk 
AKAKAKAK
*/
#include<bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;


ll n,m,pos,a[N],summ,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	pos=1;
	ans=1;
	for(int i=1;i<=n;i++){
		while(summ>m){
			//del pos
			summ-=(a[i]-a[pos]);
			pos++;
		}
		ans=max(ans,i-pos+1);
		summ+=(i-pos+1)*(a[i+1]-a[i]);
	}
	cout<<ans<<"\n";
	return 0; 
}