#include<bits/stdc++.h>
using namespace std;
int n,c[200005];
long long a[200005],cg;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char t;
		cin>>a[i]>>t;
		c[i]=int(t-'a');
	}
	int l=1,r=n;
	while(l<r){
		long long m=min(a[l],a[r]);
		if(c[l]!=c[r])cg+=m;
		if(a[l]<a[r]){
			l++;
			a[r]-=m;
		}
		else if(a[l]==a[r]){
			l++;
			r--;
		}
		else{
			a[l]-=m;
			r--;
		}
	}
	cout<<cg;
	return 0;
} 
