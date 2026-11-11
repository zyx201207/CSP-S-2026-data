#include <bits/stdc++.h>
using namespace std;
long long ans=0;
long long n,a[200005],k=1;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int temp;
		char temp1;
		cin>>temp>>temp1;
		if(temp1==b[k-1]){
			a[k-1]+=temp;
		}
		else{
			a[k]=temp;
			b[k]=temp1;
			k++;
		}
	}
	k--;
	long long l=1,r=k;
	while(l<r){
		long long temp=min(a[l],a[r]);
		if(b[l]!=b[r]){
			ans+=temp;
		}
		a[l]-=temp;
		a[r]-=temp;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
} 
