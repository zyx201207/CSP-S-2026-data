#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
long long ans;
char b[N];
int a[N];
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	int l=1,cntl=a[1],r=n,cntr=a[n];
	while(l<r){
		if(cntl==cntr){
			ans+=(b[l]==b[r]?0:cntl);
			l++;r--;
			cntl=a[l];
			cntr=a[r];
		}
		else if(cntl<cntr){
			ans+=(b[l]==b[r]?0:cntl);
			l++;
			cntr-=cntl;
			cntl=a[l];
		}
		else{
			ans+=(b[l]==b[r]?0:cntr);
			r--;
			cntl-=cntr;
			cntr=a[r];
		}
	}
	cout<<ans;
	return 0;
}
