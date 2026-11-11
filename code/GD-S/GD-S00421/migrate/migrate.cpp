#include<bits/stdc++.h>
using namespace std;
#define int long long
#define filename "migrate"
int n,c,t,d,a[200005];
signed main(){
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ifj=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i!=1&&a[i]-a[i-1]!=a[2]-a[1]){
				ifj=1;
			}
			if(i!=1&&a[i]-a[i-1]>d){
				n=i-1;
			}
		}
		if(ifj==0){
			if(d/(a[3]-a[2])==1){
				cout<<0<<endl;
				continue;
			}
			if((d/(a[3]-a[2]))>n/2){
				cout<<0<<endl;
				continue;
			}else{
				cout<<n-2*(d/(a[3]-a[2]))+1<<endl;
				continue;
			}
		}else{
			cout<<0<<endl;
		}

	}
	return 0;
}
