#include<bits/stdc++.h>
using namespace std;
long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		if(a[l]>=a[r]){
			if(c[l]!=c[r])ans+=a[r];
			a[l]-=a[r];
			r--;
			if(a[l]<=0)l++;
		}
		else{
			if(c[l]!=c[r])ans+=a[l];
			a[r]-=a[l];
			l++;
			if(a[r]<=0)r--;
		}
	}
	cout<<ans;
	return 0;
}

