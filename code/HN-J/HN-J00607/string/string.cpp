#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200005],b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a1;
		char b1;
		cin>>a1>>b1;
		a[i]=a1;
		b[i]=b1;
	}
	
	long long i=1,j=n;
	while(i!=j){
		if(b[i]!=b[j]){
			ans+=min(a[i],a[j]);
		}
		a[i]-=min(a[i],a[j]);
		a[j]-=min(a[i],a[j]);
		if(a[i]){
			j--;
		}else if(a[j]){
			i++;
		}
	}
	cout<<ans;
	
	return 0;
} 
