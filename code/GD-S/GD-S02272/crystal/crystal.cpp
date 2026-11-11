#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,standard,x,cnt,maxx=0,ans=0;
	bool f=1,ff=1;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i==2){
			x=a[2]-a[1];
		}else if(i>2){
			if(a[i]-x!=a[i-1]){
				ff=0;
			}
		}
		if(a[i]!=i){
			f=0;
		}		
	}
	sort(a+1,a+n+1);
	if(n==1){
		cout << 1 << endl;
		return 0;
	}
	if(f){
		for(int i=0;;i++){
			if(m-i>=0){
				ans++;
				m-=i;
			}else{
				break;
			}
		}
		if(ans>n){
			cout << n << endl;
		}else{
			cout << ans << endl;
		}
		return 0;
	}
	if(ff){
		for(int i=0;;i+=x){
			if(m-i>=0){
				ans++;
				m-=i;
			}else{
				break;
			}
		}
		if(ans>n){
			cout << n << endl;
		}else{
			cout << ans << endl;
		}
		return 0;
	}
	for(int i=n;i>=1;i--){
		x=0;
		cnt=1;
		standard=a[i]-a[i-1];
		for(int j=i-1;j>=1;j--){
			if(x+a[i]-a[j]<=m){
				x+=(a[i]-a[j]);
				cnt++;			
			}else{
				maxx=max(maxx,cnt);
				break;
			}
		}
		maxx=max(maxx,cnt);
	}
	cout << maxx << endl;
	return 0;
} 
