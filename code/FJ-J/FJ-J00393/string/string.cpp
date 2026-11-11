#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],b[200005],k,m,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		b[i]=c-'a'+1;
		k+=a[i];
	}
	k/=2;
	int l=1,r=n;
	while(m<k&&l!=r){
		if(b[l]!=b[r]){
			if(a[l]<a[r]){
				m+=a[l];
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else if(a[l]>a[r]){
				m+=a[r];
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else{
				m+=a[l];
				ans+=a[l];
				l++;
				r--;
			}
		}
		else{
			if(a[l]<a[r]){
				m+=a[l];
				a[r]-=a[l];
				l++;
			}
			else if(a[l]>a[r]){
				m+=a[r];
				a[l]-=a[r];
				r--;
			}
			else{
				m+=a[l];
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
