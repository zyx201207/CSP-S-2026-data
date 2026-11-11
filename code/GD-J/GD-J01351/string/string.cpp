#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+10;
int n,a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int ji=0;
	for (int i=1; i<=n; i++){
		cin>>a[i]>>c[i];
		ji+=a[i];
	}
	int ans=0,kkks=0;
	int l=1,r=n;
	while(l<r){
			
		if (a[l]!=a[r]){
				
			if (a[l]>a[r]){
				int cnt=a[r];
				if (c[l]!=c[r]) ans+=a[r];
				while(cnt<a[l]&&l<r){
					r--;
					int kji=0;
						
					if (cnt+a[r]<=a[l]){
						cnt+=a[r];
						kji=a[r];
					}
					else{
						a[r]-=a[l]-cnt;
						kji=a[l]-cnt;
						cnt+=a[l]-cnt;
							
					}
					if (c[r]!=c[l]){
						ans+=kji;
					}
				}
			
			}
			else{
				if (c[l]!=c[r]) ans+=a[l];
				a[r]-=a[l];
			}
		}
		else{
			if (c[l]!=c[r])ans+=a[l];
			a[r]=0;
		}
		l++;
	}
	cout<<ans;	
	
}
