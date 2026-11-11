#include<bits/stdc++.h>
using namespace std;

long long a[200005];
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	long long ans=0;
	long long l=1,r=n;
	while(l<r){
		long long minn=min(a[l],a[r]);
		if(c[l]!=c[r])ans+=minn;
		a[l]-=minn;
		a[r]-=minn;
		if(a[l]>a[r]){
			r--;
		}
		else if(a[l]==a[r]){
			l++;
			r--;
		}
		else{
			l++;
		}
	}
	cout<<ans;
	
	
	return 0;
} 
