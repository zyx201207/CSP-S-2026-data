#include<bits/stdc++.h>
using namespace std;
int const N=2e5+10;
int a[N],c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	char s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s;
		c[i]=s-'a'+1;
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		if(a[l]<a[r]){
			a[r]-=a[l];
			if(c[l]!=c[r])ans+=a[l];
			l++;
		}else {
			a[l]-=a[r];
			if(c[l]!=c[r])ans+=a[r];
			r--;
		}
	}
	cout<<ans;
	return 0;
} 
