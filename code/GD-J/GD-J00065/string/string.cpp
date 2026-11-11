#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],sum;
char b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<=r&&r>=1&&l<=n){
		if(a[l]==0) l++;
		if(a[r]==0) r--;
		if(a[l]<a[r]){
			if(b[l]!=b[r]){
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}else{
				a[r]-=a[l];
				l++;
			}		
		}else{
			if(b[l]!=b[r]){
				sum+=a[r];
				a[l]-=a[r];
				r--;
			}else{
				a[l]-=a[r];
				r--; 
			}
		}
		
	}
	cout<<sum;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
