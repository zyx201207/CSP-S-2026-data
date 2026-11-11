#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char s[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>s[i];
	int l=a[1],r=a[n],z=1,y=n;
	while(z<y){
		if(s[z]==s[y]){
			if(l>r){
				l-=r;
				y--;
				r=a[y];
			}else if(l<r){
				r-=l;
				z++;
				l=a[z];
			}else{
				z++;y--;
				r=a[y];
				l=a[z];
			}
		}else{
			if(l>r){
				ans+=r;
				l-=r;
				y--;
				r=a[y];
			}else if(l<r){
				ans+=l;
				r-=l;
				z++;
				l=a[z];
			}else{
				ans+=l;
				z++;y--;
				r=a[y];
				l=a[z];
			}
		}
	}
	cout<<ans;
	return 0;
} 
