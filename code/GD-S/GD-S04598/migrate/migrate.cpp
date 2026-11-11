#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,n,d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(d!=2){
			cout<<0<<endl;
			continue;
		}
		long long cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]-a[i-1]>d){
				continue;
			}
			for(int j=1;j<i;j++){
				if(d<a[i]-a[j]&&a[i]-a[j]<2*d){
					++cnt;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
