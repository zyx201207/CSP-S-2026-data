#include<bits/stdc++.h>
using namespace std;
long long c[1000009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	long long a,b;
	cin>>a>>b;
	for(long long i=1;i<=a;i++)cin>>c[i];
	sort(c+1,c+a+1);
	long long hf=0,ans=1;
	for(long long i=1,j=1;i<=a;i++){
		hf=hf+(i-j)*(c[i]-c[i-1]);
		while(hf>b)hf=hf-(c[i]-c[j]),j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
