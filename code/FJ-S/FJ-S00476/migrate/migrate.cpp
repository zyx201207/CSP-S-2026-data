#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long a[2000005],d;
int main(){
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			long long cha=a[2]-a[1];
			long long x=d/cha;
			if(x>=2){
				if(n>x+1) cout<<n-x-1;
				else cout<<0;
			}else cout<<0;
			cout<<'\n';
		}
	}
	return 0;
}
