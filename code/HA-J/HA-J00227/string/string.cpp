#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
int a[200010];
char c[200010];
#undef int 
int main(){
	#define int long long
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);	
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
		else{
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			if(a[r]==0){
				r--;
			}
			l++;
		}
	}
	cout<<ans;
	return 0;
}
