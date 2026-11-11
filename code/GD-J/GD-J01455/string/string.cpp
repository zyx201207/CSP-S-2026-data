#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<=r){
		int mi=min(a[l],a[r]);
		a[l]-=mi;
		a[r]-=mi;
		if(c[l]!=c[r])ans+=mi;
		if(a[l])r--;
		else l++;
	}
	cout<<ans;
	return 0;
}
