#include <bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
long long n,ans=0;
int main(){
	ios::sync_with_stdio(),cin.tie(),cout.tie();
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(c[l]!=c[r]){
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				a[l]=0;
			}
			else{
				ans+=a[r];
				a[l]-=a[r];
				a[r]=0;
			}
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}else{
			if(a[l]<a[r]){
				a[r]-=a[l];
				a[l]=0;
			}
			else{
				a[l]-=a[r];
				a[r]=0;
			}
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}
	}
	cout<<ans;
	return 0;
} 
//3
//2 a
//2 b
//1 c

//2
//2 a
//3 a

//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b











