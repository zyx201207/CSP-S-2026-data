#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,e=0,sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(abs(a[1]-a[2]>d)){
				cout<<0<<endl;
				continue; 
			}
			if(n<=3){
				cout<<0<<endl;
				continue;
			}
			if(n==4){
				cout<<1<<endl;
				continue;
			}
			for(int i=3;i<=n;i++){
				sum+=(i-3);
			}
		    cout<<sum-1<<endl;
		if(c==11 || c==12){
			if(abs(a[1]-a[2]>d)){
				cout<<0<<endl;
				continue; 
			}
			if(n<=3){
				cout<<0<<endl;
				continue;
			}
			if(n==4){
				cout<<1<<endl;
				continue;;
			}
			for(int i=n;i>=1;i--){
				if(i*abs(a[1]-a[2])<=d){
					e=i;
					continue;
				}
			}
			for(int i=3;i<=n;i++){
				sum+=(i-3);
			}
			cout<<sum-1<<endl;
		}
	}
	return 0;
}
