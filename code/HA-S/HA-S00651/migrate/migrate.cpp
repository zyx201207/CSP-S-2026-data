#include<bits/stdc++.h>
using namespace std;
long long c,n,t,d,a[2000010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	cin>>n>>d;
	long long s=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s+=a[i];
		}
		
		if((s-1)%d!=0){
			if(n>4){
				cout<<0;
			}
			cout<<1;
			break;
		}else{
			if(a[1]<0){
				cout<<0;
			}
			cout<<2;
		}
	}
	return 0;
}
