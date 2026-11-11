#include<bits/stdc++.h>
using namespace std;
long long m,a[500002],t[500001];
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	a[n+1]=a[n]+m+1;
	for(int i=1;i<n;i++)
		t[i]=a[i+1]-a[i];
	int l=1,r=1,cnt=1,ans=1;
	long long sum=0; bool f=false;
	while(r!=n){
		while(sum+cnt*t[r]<=m){
			sum+=cnt*t[r];
			r++; cnt++;
			ans=max(ans,cnt);
			if(r==n){
				f=true;
				break;
			}
		}
		if(f) break;
		while(sum+cnt*t[r]>m){
			
			if(l==r) { l++; r++; cnt=1; sum=0; break; }
			
			
			sum=sum-(a[r]-a[l]);
			l++; cnt--;
		}
		if(f) break;
	}
	cout<<ans;
	return 0;
}
