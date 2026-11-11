#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	long long ans=0;
	if(n==2){
		if(c[0]!=c[1]){
			ans+=min(a[0],a[1]);
		}
		cout<<ans;
		return 0;
	}
	long long l=0,r=n-1;
	
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]!=a[r]){
				if(a[l]>a[r]){
					ans+=a[l];
					a[r-1]-=(a[l]-a[r]);
				}
				else{
					ans+=a[r];
					a[l+1]-=(a[r]-a[l]);
				}
			} 
			l++;
		r--;
		}
		else{
			if(a[l]!=a[r]){
				if(a[l]>a[r]){
					ans+=a[l];
					a[r-1]-=(a[l]-a[r]);
				}
				else{
					ans+=a[r];
					a[l+1]-=(a[r]-a[l]);
				}
			}
			else{
				ans+=a[r];
			} 
			l++;
		r--;
		}
		
	}
	cout<<ans;
	return 0;
}
