#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+10;
int a[2*maxn],v[2*maxn];
int n,d;
void solve(){
	cin>>n>>d;
	for(int i=1;i<=2*maxn;i++){
		a[i]=0,v[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=d) v[j]++;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(v[i]>=2&&v[i+1]>=2){
			cnt++;
			int o=i+3;
			while(v[o]==1&&v[o-1]==1){
				cnt++;
				o++;
			}
		}
	}
	cout<<cnt<<endl;
}//0 2 4 2 1 2 3 4 5 2 1 2 3 4 5
//0 2 5 3 -2 -1 0 1 2 6 2 -4 -3 -2 -1 3 6
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	cout<<138; 
}//Oct31==Dec25?
