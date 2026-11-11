#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500010],ans;
char c[500010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n,x=0,sum;
	for(int i=1;i<r;i++){
		while(a[i]>0&&r>i){
			if(a[i]-a[r]<0){
				a[r]-=a[i];
				if(c[r]!=c[i]) ans+=a[i];
				break;
			}else{
				a[i]-=a[r];
				if(c[r]!=c[i]) ans+=a[r];
				r--;
			}
		}
	}
	cout<<ans;
}
