#include<bits/stdc++.h> 
using namespace std;
long long c,t,n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=2){
			cout<<0<<"\n";
		}
		else if(c>0 and c<26){
			if(a[1]<0){
				if(a[1]+1e18<a[2]){
					cout<<0<<"\n";
					continue;
				}
			}
			long long am=a[2]-a[1],dd;
			if(2*am>d){
				cout<<0<<"\n";
			}
			else if((2*am)<=d){
				dd=2*d/am-1;
				if(n>=dd){
					cout<<n-dd<<"\n";
				}
				else{
					cout<<0<<"\n";
				}
				
			}
		}
		else{
			
		}
	}
	return 0;
}
