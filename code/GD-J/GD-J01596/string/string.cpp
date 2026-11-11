#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		int x=a[l];
		int y=a[r];
		if(c[l]!=c[r]){
			if(x>y){
				ans+=y;
				a[l]-=y;
				r--;
			}else{
				ans+=x;
				a[r]-=x;
				l++;
			}
		}else{
			if(x>y){
				a[l]-=y;
				r--;
			}else{
				a[r]-=x;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
