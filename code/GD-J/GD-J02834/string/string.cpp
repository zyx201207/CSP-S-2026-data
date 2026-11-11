#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200001],ans=0;
	char b[200001];
	cin>>n;
	long long l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(l<r){
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
		if(b[l]!=b[r]){
			ans+=min(a[l],a[r]);
		}
		a[l]-=min(a[l],a[r]);
		a[r]-=min(a[l],a[r]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
