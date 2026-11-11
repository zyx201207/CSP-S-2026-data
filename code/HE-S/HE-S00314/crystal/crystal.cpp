#include<bits/stdc++.h>
long long n,m;
const int N=5e5+10;
int a[N];
int s,r,l,i;
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
			int ans=0;
			for(int i=1;i<=n;i++)int l=0,r=i-1,res=i-1;
					while(l<=r){
					int mid=(l+r)>>1;
					if(i-mid>l+r) {
						ans++;
					}
				}
	cout<<ans;			
	return 0;
}
      
