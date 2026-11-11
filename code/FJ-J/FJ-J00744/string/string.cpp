#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[200005];
char ch[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(ch[l]!=ch[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}else if(a[r]>a[l]){				
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}else{
				ans+=a[l];
				l++;
				r--;
			}
			
		}else{
			if(a[l]>a[r]){
				
				a[l]-=a[r];
				r--;
			}else if(a[r]>a[l]){
				
				a[r]-=a[l];
				l++;
			}else{
				l++;
				r--;
			}
		}
		
	}
	cout<<ans;
	return 0;
}
