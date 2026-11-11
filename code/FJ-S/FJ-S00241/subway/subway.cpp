#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans=0,flag=0;
int w[10005]={0},a[1005][10005]{0},t[1005][10005]={0};
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	int i=n;
	int k[n+5]={0};
	for(int i=1;i<=n;i++){
		int cnt=0;
		cin  >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];	
		}
		cnt++;
	}
	int r=q;
	int x[r+5]={0},y[r+5]={0};
	for(int i=1;i<=r;i++){
		cin >> x[i] >> y[i];
	}
	ans+=w[1];
	for(int g=1;g<=r;g++){
		for(int b=x[i];b<=y[i];b++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=k[i];j++){
					if(a[i][j]==b){
						ans+=t[i][j];
						flag=1;
						continue;
					}
				}
			}
			if(flag==0){
				ans+=w[i];
			}
			flag=0;
		}
		cout << ans << endl;
		ans=0;
	}
	
	
	return 0;
}
