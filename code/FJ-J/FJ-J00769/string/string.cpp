#include<bits/stdc++.h>
using namespace std;
long long sum;
int n,a[500001];
char b[500001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>b[i];
	}
	int l=0,r=n;
	for(;l<=r;){
		if(b[l]==b[r]){
			if(a[l]<a[r])a[r]-=a[l],a[l]=0,l++;
			else  if(a[l]==a[r]) a[l]=0,a[r]=0,l++,r--;
			else a[l]-=a[r],a[r]=0,r--;
		}
		if(b[l]!=b[r]){
			sum+=min(a[l],a[r]);
			if(a[l]<a[r])a[r]-=a[l],a[l]=0,l++;
			else  if(a[l]==a[r]) a[l]=0,a[r]=0,l++,r--;
			else a[l]-=a[r],a[r]=0,r--;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
