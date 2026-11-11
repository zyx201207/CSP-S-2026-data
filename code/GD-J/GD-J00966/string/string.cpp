#include<bits/stdc++.h>
using namespace std;
long long n,s;
long long a[200005];
char c[200005]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i]; 
	}
	long long l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			long long x=min(a[l],a[r]);
			s+=x;a[l]-=x;a[r]-=x;
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}
		else {
			long long x=min(a[l],a[r]);
			a[l]-=x;a[r]-=x;
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}
	}
	cout<<s;
	
	return 0;
}
