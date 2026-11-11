#include<bits/stdc++.h>
#define int long long
using namespace std;
char a[200005];
int b[200005];
signed main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		char x;
		cin>>b[i]>>x;
		a[i]=x;
		sum+=b[i];
	}
	int l=0,r=n-1,ans=0,lx=0,rx=sum;
	while(l<r){
		int p=min(b[l],b[r]);
		if(a[l]!=a[r])ans+=p;
		b[l]-=p;b[r]-=p;
		if(b[l]==0)l++;
		if(b[r]==0)r--;
	}
	cout<<ans;
}
