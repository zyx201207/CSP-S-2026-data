#include<bits/stdc++.h>
using namespace std;
int c,T;
int n;
long long d;
long long a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c>=11&&c<=12){
			int g=a[1]-a[0];
			if(g<d&&d<3*g) cout<<n-3;
			else cout<<0;
		}else if(c>=13&&c<=14){
			int x;
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
					x=i;
					break;
				}
			}
			int ans=0;
			if(x>2&&a[x+1]-a[x-2]>d) ans++;
			if(x>1&&a[x+2]-a[x-1]>d) ans++;
			cout<<ans;
		}else{
			int ans=0;
			for(int i=1;i<=n-3;i++){
				int j=i+3;
				if(a[j]-a[i]>d&&a[j]-a[j-1]<=d&&a[j-1]-a[i]<=d&&a[j]-a[i+1]<=d&&a[i+1]-a[i]<=d){
					ans++;
				}
			}
			cout<<ans;
		}
		cout<<endl;
	}
	return 0;
}
