#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5+5;
int l=1,r,lc,rc,n;
long long a[MAX_N],ans=0;
char c[MAX_N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	r=n;
	lc=a[1];
	rc=a[n];
	do{
		if(c[l]==c[r]){
			if(lc>rc){
				lc-=rc;
				rc=a[--r];
			}else{
				rc-=lc;
				lc=a[++l];
			}
		}else{
			if(lc>rc){
				ans+=rc;
				lc-=rc;
				rc=a[--r];
			}else{
				ans+=lc;
				rc-=lc;
				lc=a[++l];
			}
		}
	}while(l!=r);
	cout<<ans<<"\n";
	return 0;
}
