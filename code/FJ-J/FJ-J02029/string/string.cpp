#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200050];
char c[200050]; 
int m=0,n=0,ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		n+=a[i];
		cin>>c[i];
	}
	ans=n/2;
	int lc=1,rc=m;
	while(lc<=rc){
		if(c[lc]==c[rc]){
			if(a[lc]>=a[rc]){
				if(lc==rc) ans-=a[rc]/2;
				else ans-=a[rc];
				if(a[lc]==a[rc]){
					lc++;
					rc--;
				} else{
					a[lc]-=a[rc];
					rc--;
				}
			}else{
				ans-=a[lc];
				a[rc]-=a[lc];
				lc++;
			}
		}else{
			if(a[lc]>=a[rc]){
				if(a[lc]==a[rc]){
					lc++;
					rc--;
				} else{
					a[lc]-=a[rc];
					rc--;
				}
			}else{
				a[rc]-=a[lc];
				lc++;
			}
		} 
	}
	cout<<ans;
} 
