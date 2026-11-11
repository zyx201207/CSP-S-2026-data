#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int i=1,j=n;
	while(i<j){
		if(c[i]!=c[j])ans+=min(a[i],a[j]);
		if(a[i]<a[j])a[j]-=a[i],i++;
		else if(a[j]<a[i])a[i]-=a[j],j--;
		else i++,j--;
	}
	cout<<ans;
	return 0;
}
