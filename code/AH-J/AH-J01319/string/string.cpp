#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	int l=1,r=n;
	long long ans=0;
	while(l<=r){
		if(c[l]==c[r]){
			if(a[l]>=a[r]){
				a[l]-=a[r];
				r--;
			}else{
				a[r]-=a[l];
				l++;
			}
		}else{
			if(a[l]>=a[r]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}else{
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
