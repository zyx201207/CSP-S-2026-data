#include<bits/stdc++.h>
using namespace std;
long long a[1001000],b[1001000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		long long ans=0;
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long l=1,r=3,x=a[2]-a[1],y=a[3]-a[2],z=a[4]-a[3];
		while(l<=n-3){
			if(x+y<=d&&y+z<=d&&x+y+z>d&&r<n-1){
				ans++;
				r++;
				z+=(a[r+1]-a[r]);
			}else{
				l++;
				r=l+2;
				x=a[l+1]-a[l];
				y=a[l+2]-a[l+1];
				z=a[l+3]-a[l+2];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
