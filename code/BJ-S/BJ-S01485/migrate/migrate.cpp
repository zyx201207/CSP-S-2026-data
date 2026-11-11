#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

long long n,T,m,a[600100],h[600100],v[600100],c1,c2=1,r,l,mn,mid,x,ans,c,d,q,ln[1000][1000];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> T;
    while(T--){
		c1=0;
		c2=1;
		cin >> n >> m;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		a[n+1]=a[n+2]=a[n+3]=a[n+4]=1e18;
		for(int i=1;i<=n-2;i++){
			if(a[i]+m>=a[i+1]&&a[i]+m<a[i+2]&&a[i+1]+m>=a[i+2]){
				v[i+1]=v[i]+1;
			}
		}
		for(int i=n;i>=1;i--){
			if(v[i]>0&&v[i+1]>0){
				v[i]=v[i+1];
			}
			//cout << v[i] << ' ';
		}
		//cout << endl;
		for(int i=1;i<=n-1;i++){
			if(a[i]+m<a[i+3]){
				if(a[i+1]+m>=a[i+3]){
					//cout << i <<' ' << i+3 << endl;
					ans+=(v[i]+1)*(v[i+3]+1);
				}
			}
		}
		cout << ans << endl;
		ans=0;
		for(int i=1;i<=n;i++){
			v[i]=0;
		}
	}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
