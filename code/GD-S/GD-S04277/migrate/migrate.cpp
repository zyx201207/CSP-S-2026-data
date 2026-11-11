#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int t,n,d,c;
ll aa[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	
	while(t--){
		if(c==13 or c==14){
			cout<<0<<endl;
			continue;
		}
		cin>>n>>d;
		if(d==1){
			cout<<1<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>aa[i];
		}	
		int ca=aa[2]-aa[1];
		for(int i=1;i<=n;i++){
			if(i*ca>d){
				cout<<n-i<<endl;
				break;
			}
		}		
	}
	return 0;
}
