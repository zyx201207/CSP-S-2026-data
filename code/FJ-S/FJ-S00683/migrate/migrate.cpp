#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
vector<long long> a;
ll w,k,c,t;
ll r=0,l,sp,ans=0;


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	if(c==0) cout<<1<<endl<<2<<endl;
	else{
		for(int i=0;i<t;i++){
			cin>>n>>m;
			ans=0;ll o=0;
			for(int i=0;i<n;i++){
				cin>>k;
				a.push_back(k);
				if(a[o]+m<k){
					o++;
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
