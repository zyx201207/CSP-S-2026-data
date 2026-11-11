#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	
	int r=1,l=n;
	while(r<l){
		if(a[r]>=a[l]){
			a[r]-=a[l];
			if(c[r]!=c[l]){
				ans+=a[l];
			}
			if(a[r]==0){
				r++;
			}
			l--;
		}else{
			a[l]-=a[r];
			if(c[r]!=c[l]){
				ans+=a[r];
			}
			r++;
		}
	}
	cout<<ans;
}
