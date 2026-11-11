#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+10; 
int n;
int ans=0;
int x[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(c[l]==c[r]){
			if(x[l]<x[r])x[r]-=x[l],l++;
			else if(x[r]<x[l])x[l]-=x[r],r--;
			else l++,r--;
		}
		else {
			if(x[l]<x[r]){
				ans+=min(x[r],x[l]);
				x[r]-=x[l];l++;
			}
			else if(x[r]<x[l]){
				ans+=min(x[r],x[l]);
				x[l]-=x[r],r--;
			}
			else {
				ans+=min(x[r],x[l]);
				r--,l++;
			}
		}
		if(l>r)break;
	}
	cout<<ans;
	return 0;
} 
