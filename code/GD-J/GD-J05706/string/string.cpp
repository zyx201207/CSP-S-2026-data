#include <bits/stdc++.h>
using namespace std;
long long n,a[200010],ans,x;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	for(int i=1,j=n;;){
		if(i==j)
			break;
		if(c[i]!=c[j])
			ans+=min(a[i],a[j]);
		a[i]-=min(a[i],a[j]),a[j]-=min(a[i],a[j]);
		if(a[i]==0)
			i++;
		if(a[j]==0)
			j--;
	}
	cout<<ans;
	return 0; 
}
