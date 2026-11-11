//OK 
#include<bits/stdc++.h>
using namespace std;
#define MAXN 200100
long long n,a[MAXN],l=1ll,r,ans;
char c[MAXN]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(l<r){
		long long mn=min(a[l],a[r]);
		a[l]-=mn,a[r]-=mn;
		if(c[l]!=c[r])ans+=mn;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<ans;
} 
