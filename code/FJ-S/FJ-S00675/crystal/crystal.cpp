#include <bits/stdc++.h>
using namespace std;
long long n,m,zc,a[500100],c[500100],cnt,nl,ans=0;
bool f=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i-1]<a[i]){
			c[i-1]=a[i]-a[i-1];
		}
		if(i>2 && c[i-1]!=c[i-2]){
			f=0;
		}
	}
	if(f==1){
		for(long long i=1;i<=n-1;i++){
			if((i+1)%2==1){
				if((i+1)/2*i*c[1]>m){
					break;
				}
			}else{
				if(i/2*(i+1)*c[1]>m){
					break;
				}
			}
			ans++;
		}
		cout << ans+1;
		return 0;
	}
	sort(a+1,a+n+1);
	cnt=n;
	nl=m;
	for(int i=n;i>1;i--){
		cnt=i;
		nl=m;
		zc=0;
		while(cnt>0 && nl>0){
			zc+=c[cnt-1];
			if(nl>=zc){
				nl-=zc;
				cnt--;
			}else{
				break;
			}
			//cout << i << " " << cnt << " " << nl << " " <<  endl;
		}
		ans=max(i-max(cnt,1ll)+1,ans);
		if(ans==n || ans>=i){
			break;
		}
	}
	cout << ans;
	
	return 0;
}

