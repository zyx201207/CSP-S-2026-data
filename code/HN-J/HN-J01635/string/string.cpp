#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[200011];
char c[200011];
int n;
long long ans=n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		if(a[l]<a[r]){
			if(c[l]!=c[r]) ans+=a[l];
			a[r]-=a[l];
			a[l]=0;
			l++;
		}
		else if(a[l]==a[r]){
			if(c[l]!=c[r]) ans+=a[l];
			a[r]=a[l]=0;
			l++,r--;
		}
		else if(a[l]>a[r]){
			if(c[l]!=c[r]) ans+=a[r];
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

