#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans;
char b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1,j=n;i<=j;){
		int mi=min(a[i],a[j]);
		if(b[i]!=b[j])ans+=mi;
		a[i]-=mi;if(a[i]<=0)i++;
		a[j]-=mi;if(a[j]<=0)j--;
	}
	cout<<ans;
}
