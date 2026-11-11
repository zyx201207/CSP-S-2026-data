#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,a[200010],sum;
char c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				sum+=a[r];
				a[l]-=a[r];
				r--; 
			}else if(a[l]<a[r]){ 
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}else{
				sum+=a[l];
				l++,r--;	
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--; 
			}else if(a[l]<a[r]){ 
				a[r]-=a[l];
				l++;
			}else{

				l++,r--;
			}
		}
	}	
	cout<<sum;
	return 0;
}
