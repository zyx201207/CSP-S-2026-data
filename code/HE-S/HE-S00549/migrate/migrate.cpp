#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d,w=1,cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int l=1,r=2;
		while(l<r&&r<=d){
			int x=d;
			if(a[r]-a[l]<=x){
				r++;
				cnt++;
			}else break;
		}
		cout<<cnt/2<<"\n";
	}
	return 0;
}
